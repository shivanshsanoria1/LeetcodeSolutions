import json
import config
import matplotlib.pyplot as plt
from datetime import datetime, timezone
from collections import defaultdict
from typing import List, Dict
# ------------------------------ #

def getColorHex(color: str) -> str:
	colorMapping = {
		'pink': '#800080',
		'violet': '#7300e6',
		'light-blue': '#00ccff',
		'blue': '#3366ff',
		'sea-green': '#00b386',
		'light-green': '#00e64d',
		'green': '#39ac39',
		'yellow': '#ffff66',
		'orange': '#ff751a',
		'red': '#ff4d4d',
		'grey': '#dedede',
	}
	defaultColor = '#000000' 

	color = color.strip().lower()
	return colorMapping.get(color, defaultColor)
# ------------------------------ #

def getCurrUTCstring() -> str:
	return datetime.now(timezone.utc).strftime('%Y-%m-%d %H:%M:%S UTC')
# ------------------------------ #

def loadArr() -> List[Dict]:
	filePathJS = './stats/generated/leetcode-stats-array.js'

	with open(filePathJS, 'r') as file:
		arrayJS = file.read()

	stats = json.loads(arrayJS)

	return stats
# ------------------------------ #

def generateTotalCounter(stats: List[Dict]) -> Dict:
	counter = {
		"accepted": 0,
		"partiallyAccepted": 0,
		"unaccepted": 0
	}

	maxQuesId = config.maxQuesId

	counter["accepted"] = sum(1 for question in stats if question['isAccepted'])
	counter["partiallyAccepted"] = len(stats) - counter["accepted"]
	counter["unaccepted"] = maxQuesId - len(stats)

	return counter
# ------------------------------ #

def plotPieChartTotalCount(counter: Dict, showChart: bool = True) -> None:
	labelMapping = {
		"accepted": ("Accepted", getColorHex('green')), 
		"partiallyAccepted": ("Partially Accepted", getColorHex('yellow')),
		"unaccepted": ("Not Attempted", getColorHex('red')), # red
	}

	labels = counter.keys()
	displayLabels, colors = zip(*[labelMapping[label] for label in labels])

	sizes = counter.values()

	plt.figure(figsize = (8, 6), facecolor = getColorHex('grey'))
	plt.pie(
		sizes, 
		labels = displayLabels, 
		colors = colors,
		autopct = '%1.2f%%', 
		startangle = 140,
		wedgeprops = dict(edgecolor = 'none')  # Remove the edge to eliminate gaps
	)

	plt.axis('equal')
	plt.title(f'Problem Acceptance Status\nLast Updated on: {getCurrUTCstring()}') 
	plt.savefig('./stats/generated/img/pie-chart-total-count.png', format = 'png') 
	if showChart: 
		plt.show()
# ------------------------------ #

def generateTypeCounter(stats: List[Dict]) -> Dict:
    counter = {}

    for stat in stats:
        if not stat.get('isAccepted'):
            continue

        typ = stat.get('type')

        counter[typ] = counter.get(typ, 0) + 1

    return counter
# ------------------------------ #

def plotPieChartTypeCount(counter: Dict, showChart: bool = True) -> None:
	labelMapping = {
		"general": ("General", getColorHex('blue')),
		"database": ("Database", getColorHex('green')),
		"javascript/typescript": ("Javascript / Typescript", getColorHex('yellow')),
	}

	labels = counter.keys()
	displayLabels, colors = zip(*[labelMapping[label] for label in labels])

	sizes = counter.values()

	plt.figure(figsize = (8, 6), facecolor = getColorHex('grey'))
	plt.pie(
		sizes, 
		labels = displayLabels, 
		colors = colors,
		autopct = '%1.2f%%', 
		startangle = 140,
		wedgeprops = dict(edgecolor = 'none')  # Remove the edge to eliminate gaps
	)

	plt.axis('equal')
	plt.title(f'Probelm Type Distribution\nLast Updated on: {getCurrUTCstring()}') 
	plt.savefig('./stats/generated/img/pie-chart-type-count.png', format = 'png') 
	if showChart: 
		plt.show()
# ------------------------------ #

def generateLanguageCounter(stats: List[Dict]) -> Dict[str, int]:
    counterLang = defaultdict(int)

    for stat in stats:
        if not stat.get('isAccepted'):
            continue

        counter = stat.get('counter', {})
        for lang, count in counter.items():
            counterLang[lang] += 1

    return dict(counterLang)
# ------------------------------ #

def plotBarChartLanguageCounter(counterLang: Dict[str, int], showChart: bool = True) -> None:
	languageMapping = {
		"cpp": ("C++", getColorHex('blue')),
		"js": ("JavaScript", getColorHex('yellow')),
		"mysql": ("MySQL", getColorHex('green')), 
	}

	sortedItems = sorted(counterLang.items(), key=lambda kv: kv[1], reverse=True)

	languages = [lang for lang, _ in sortedItems]
	values = [cnt for _, cnt in sortedItems]

	labels = [languageMapping.get(lang, (lang, getColorHex('')))[0] for lang in languages]
	colors = [languageMapping.get(lang, (lang, getColorHex('')))[1] for lang in languages]

	plt.figure(figsize=(8, 5), facecolor = getColorHex('grey'))
	bars = plt.bar(labels, values, color=colors)

	plt.xlabel('Language')
	plt.ylabel('Problems solved')
	plt.title(f'Accepted Solutions per Language\nLast Updated on: {getCurrUTCstring()}')
	plt.grid(axis = 'y', linestyle = '--', alpha = 0.6)

	for bar in bars:
		height = bar.get_height()
		plt.annotate(
			f'{height}',
			xy = (bar.get_x() + bar.get_width() / 2, height),
			xytext = (0, 3),
			textcoords = 'offset points',
			ha = 'center', 
			va = 'bottom'
		)

	plt.tight_layout()
	plt.savefig('./stats/generated/img/bar-chart-language-count.png', format = 'png') 
	if showChart:
		plt.show()
# ------------------------------ #

def generateHistogramBuckets(stats: List[Dict], bucketSize: int = 100) -> List[int]:
    maxQuesId = 0
    for stat in stats:
        if stat.get('isAccepted'):
            maxQuesId = max(maxQuesId, stat.get('quesId'))

    bucketCount = (maxQuesId - 1) // bucketSize + 1
    buckets = [0] * bucketCount

    for stat in stats:
        if not stat.get('isAccepted'):
            continue

        quesId = stat.get('quesId')

        bucketIdx = (quesId - 1) // bucketSize
        buckets[bucketIdx] += 1

    return buckets
# ------------------------------ #

def getBarColor(height: int) -> str:
	colors10 = [
		getColorHex('red'), # 1-10
		getColorHex('red'), # 11-20
		getColorHex('orange'), # 21-30
		getColorHex('yellow'), # 31-40
		getColorHex('sea-green'), # 41-50
		getColorHex('light-blue'), # 51-60
		getColorHex('blue'), # 61-70
		getColorHex('blue'), # 71-80
		getColorHex('violet'), # 81-90
		getColorHex('pink'), # 91-100
	]

	idx = min((height - 1) // 10, len(colors10) - 1)
	return colors10[idx]
# ------------------------------ #

def plotQuesIdHistogram(buckets: List[int], bucketSize: int = 100, showChart: bool = True) -> None:
	labels = [
		f"{i * bucketSize + 1}-{i * bucketSize + bucketSize}"
		for i in range(len(buckets))
	]

	barColours = [getBarColor(cnt) for cnt in buckets]

	fig, ax = plt.subplots(figsize = (12, 5))
	bars = ax.bar(labels, buckets, color = barColours)

	ax.set_xlabel("Problem Id range")
	ax.set_ylabel("Number of accepted problems")
	ax.set_title(f"Accepted solutions per {bucketSize} problems\nLast updated on {getCurrUTCstring()}")
	ax.grid(axis = "y", linestyle = "--", alpha = 0.6)
	plt.xticks(rotation = 45, ha = "right")
	plt.tight_layout()

	for rect, count in zip(bars, buckets):
		y = rect.get_height()
		offset = max(buckets) * 0.01
		ax.text(
			rect.get_x() + rect.get_width() / 2,
			y + offset,
			f"{count:,}",
			ha="center",
			va="bottom",
			fontsize=9,
			color="black",
		)

	plt.subplots_adjust(top = 0.90)
	plt.savefig('./stats/generated/img/histogram-chart-ques-id.png', format = 'png') 
	if showChart:
		plt.show()
# ------------------------------ #

if __name__ == '__main__':
	statsArr = loadArr()
	print(statsArr[0])

	counterTotal = generateTotalCounter(statsArr)
	print(counterTotal)

	counterType = generateTypeCounter(statsArr)
	print(counterType)

	counterLang = generateLanguageCounter(statsArr)
	print(counterLang)

	buckets = generateHistogramBuckets(statsArr, 100)
	print(buckets)

	showChart = False
	plotPieChartTotalCount(counterTotal, showChart)
	plotPieChartTypeCount(counterType, showChart)
	plotBarChartLanguageCounter(counterLang, showChart)
	plotQuesIdHistogram(buckets, 100, showChart)

# ------------------------------ #