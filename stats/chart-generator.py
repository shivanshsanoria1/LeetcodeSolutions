import json
import config
import matplotlib.pyplot as plt
from datetime import datetime, timezone
from collections import defaultdict
from typing import List, Dict
# ------------------------------

def getColorHex(color: str) -> str:
	colorMapping = {
		'green': '#66ff66',
		'blue': '#3366ff',
		'yellow': '#ffff66',
		'red': '#ff4d4d',
		'grey': '#dedede',
	}
	defaultColor = '#000000' 

	color = color.strip().lower()
	return colorMapping.get(color, defaultColor)
# ------------------------------

def getCurrUTCstring():
	return datetime.now(timezone.utc).strftime('%Y-%m-%d %H:%M:%S UTC')
# ------------------------------

def loadArr():
	filePathJS = './stats/generated/leetcode-stats-array.js'

	with open(filePathJS, 'r') as file:
		arrayJS = file.read()

	statsArr = json.loads(arrayJS)

	return statsArr
# ------------------------------

def generateTotalCounter(statsArr):
	counter = {
		"accepted": 0,
		"partiallyAccepted": 0,
		"unaccepted": 0
	}

	maxQuesId = config.maxQuesId

	counter["accepted"] = sum(1 for question in statsArr if question['isAccepted'])
	counter["partiallyAccepted"] = len(statsArr) - counter["accepted"]
	counter["unaccepted"] = maxQuesId - len(statsArr)

	return counter
# ------------------------------

def generatePieChartTotalCount(counter):
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
	plt.show()
# ------------------------------

def generateTypeCounter(statsArr):
    counter = {}

    for statObj in statsArr:
        if not statObj.get('isAccepted'):
            continue

        typ = statObj.get('type')
        if typ is None:
            continue

        counter[typ] = counter.get(typ, 0) + 1

    return counter
# ------------------------------

def generatePieChartTypeCount(counter):
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
	plt.show()
# ------------------------------

def generateLanguageCounter(stats: List[Dict]) -> Dict[str, int]:
    counterLang = defaultdict(int)

    for stat in stats:
        if not stat.get('isAccepted'):
            continue

        counter = stat.get('counter', {})
        for lang, count in counter.items():
            counterLang[lang] += 1

    return dict(counterLang)
# ------------------------------

def generateBarChartLanguageCounter(counterLang: Dict[str, int]) -> None:
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
	plt.grid(axis='y', linestyle='--', alpha=0.6)

	for bar in bars:
		height = bar.get_height()
		plt.annotate(f'{height}',
		xy=(bar.get_x() + bar.get_width() / 2, height),
		xytext=(0, 3),
		textcoords='offset points',
		ha='center', va='bottom')

	plt.tight_layout()
	plt.savefig('./stats/generated/img/bar-chart-language-count.png', format = 'png') 
	plt.show()
# ------------------------------

def main():
	statsArr = loadArr()
	print(statsArr[0])

	counterTotal = generateTotalCounter(statsArr)
	print(counterTotal)

	counterType = generateTypeCounter(statsArr)
	print(counterType)

	counterLang = generateLanguageCounter(statsArr)
	print(counterLang)

	generatePieChartTotalCount(counterTotal)
	generatePieChartTypeCount(counterType)
	generateBarChartLanguageCounter(counterLang)
# ------------------------------

main()