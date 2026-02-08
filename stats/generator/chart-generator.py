import json
import config
import matplotlib.pyplot as plt
from datetime import datetime, timezone
from collections import defaultdict
from typing import List, Dict
# ------------------------------ #

maxQuesId = getattr(config, "MAX_QUES_ID", 0)
enableLogger = getattr(config, "ENABLE_LOGGER", True)
saveChart = getattr(config, "SAVE_CHART", True)
showChart = getattr(config, "SHOW_CHART", False)
# ------------------------------ #

def getColorHex(color: str) -> str:
	colorMapping = {
		'pink': '#cc0066',
		'dark-pink': '#993366',
		'faded-purple': '#862d86',
		'purple': '#9900cc',
		'violet': '#7300e6',
		'light-blue': '#00ccff',
		'slate-blue': '#0099ff',
		'blue': '#3366ff',
		'dark-blue': '#0044cc',
		'sea-green': '#00b386',
		'light-green': '#00e68a',
		'green': '#39ac39',
		'yellow': '#ffff66',
		'orange': '#ff751a',
		'orange-red': '#ff5c33',
		'red': '#ff4d4d',
		'dark-red': '#990033',
		'grey': '#dedede',
	}

	defaultColor = '#000000' 
	color = color.strip().lower()

	return colorMapping.get(color, defaultColor)
# ------------------------------ #

def getCurrUTCstring() -> str:
	return datetime.now(timezone.utc).strftime('%Y-%m-%d %H:%M:%S UTC')
# ------------------------------ #

def logMsg(msg) -> None:
	if enableLogger:
		print(msg)
# ------------------------------ #

def chartShowSave(plt, chartName: str) -> None:
	if saveChart:
		filePath = f'./stats/generated/img/{chartName}.png'
		plt.savefig(filePath, format = 'png') 

	if showChart: 
		plt.show()
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

	counter["accepted"] = sum(1 for question in stats if question['isAccepted'])
	counter["partiallyAccepted"] = len(stats) - counter["accepted"]
	counter["unaccepted"] = maxQuesId - len(stats)

	return counter
# ------------------------------ #

def plotPieChartTotalCount(counter: Dict) -> None:
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

	chartShowSave(plt, 'pie-chart-total-count')
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

def plotPieChartTypeCount(counter: Dict) -> None:
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
	plt.title(f'Solved Problem Type Distribution\nLast Updated on: {getCurrUTCstring()}') 

	chartShowSave(plt, 'pie-chart-type-count')
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

def plotBarChartLanguageCounter(counterLang: Dict[str, int]) -> None:
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
	plt.title(f'Problems solved per Language\nLast Updated on: {getCurrUTCstring()}')
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

	chartShowSave(plt, 'bar-chart-language-count')
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
	# size = 20
	colors = [
		getColorHex('red'), # 1‑5
        getColorHex('red'), # 6‑10
        getColorHex('dark-red'), # 11‑15
        getColorHex('dark-red'), # 16‑20
        getColorHex('orange-red'), # 21‑25
        getColorHex('orange'), # 26‑30
        getColorHex('yellow'), # 31‑35
        getColorHex('light-green'), # 36‑40
        getColorHex('green'), # 41‑45
        getColorHex('sea-green'), # 46‑50
        getColorHex('light-blue'), # 51‑55
        getColorHex('slate-blue'), # 56‑60
        getColorHex('blue'), # 61‑65
        getColorHex('blue'), # 66‑70
        getColorHex('dark-blue'), # 71‑75
        getColorHex('dark-blue'), # 76‑80
        getColorHex('violet'), # 81‑85
        getColorHex('purple'), # 86‑90
        getColorHex('pink'), # 91‑95
        getColorHex('dark-pink'), # 96‑100
	]

	groupSize = 100 // len(colors)
	idx = min((height - 1) // groupSize, len(colors) - 1)

	return colors[idx]
# ------------------------------ #

def plotQuesIdHistogram(buckets: List[int], bucketSize: int = 100) -> None:
	labels = [
		f"{i * bucketSize + 1}-{i * bucketSize + bucketSize}"
		for i in range(len(buckets))
	]

	barColours = [getBarColor(cnt) for cnt in buckets]

	fig, ax = plt.subplots(figsize = (12, 5), facecolor = getColorHex('grey'))
	bars = ax.bar(labels, buckets, color = barColours, width = 0.90)

	ax.set_xlabel("Question Id range")
	ax.set_ylabel("Questions solved")
	ax.set_title(f"Questions solved per {bucketSize} questions\nLast updated on {getCurrUTCstring()}")
	ax.grid(axis = "y", linestyle = "--", alpha = 0.6)
	ax.set_ylim(top = 100)
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

	chartShowSave(plt, 'histogram-chart-ques-id')
# ------------------------------ #

if __name__ == '__main__':
	stats = loadArr()
	# logMsg(stats[0])

	counterTotal = generateTotalCounter(stats)
	logMsg(counterTotal)

	counterType = generateTypeCounter(stats)
	logMsg(counterType)

	counterLang = generateLanguageCounter(stats)
	logMsg(counterLang)

	buckets = generateHistogramBuckets(stats, 100)
	logMsg(buckets)

	plotPieChartTotalCount(counterTotal)
	plotPieChartTypeCount(counterType)
	plotBarChartLanguageCounter(counterLang)
	plotQuesIdHistogram(buckets, 100)
# ------------------------------ #