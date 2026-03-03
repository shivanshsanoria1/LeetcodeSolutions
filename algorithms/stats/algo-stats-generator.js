const path = require('node:path');
const fs = require('node:fs/promises');

function loadFromJSON() {
	return new Promise(async (resolve, reject) => {
		try {
			const jsonFilePath = path.join(__dirname, '..', '..', 'algorithms', 'stats', 'algo-stats.json')
			const fileData = await fs.readFile(jsonFilePath, { encoding: "utf8" })
			const algos = JSON.parse(fileData)

			algos.sort((a, b) => a.title.localeCompare(b.title, undefined, { sensitivity: 'accent' }))

			resolve(algos);

		} catch (err) {
			console.log(err);
			reject();
		}
	});
}

function generateMDlinksFileForAlgos(algos) {
	return new Promise(async (resolve, reject) => {
		try {
			let fileDataStringified = '';
			fileDataStringified += '| Title | Difficulty | Prerequisite | Similar | Followup |\n';
			fileDataStringified += '| --- | --- | --- | --- | --- |\n';

			for(const algo of algos){
				const {id, title, difficulty} = algo

				fileDataStringified += `| ${title} | ${difficulty} | `

				const prerequisite = algo.linked && algo.linked.prerequisite ? algo.linked.prerequisite : []
				const similar = algo.linked && algo.linked.similar ? algo.linked.similar : []
				const followup = algo.linked && algo.linked.followup ? algo.linked.followup : []
				
				const linked = [prerequisite, similar, followup]

				for(const ids of linked){
					for(let i=0; i < ids.length; i++){
						const algo = algos.find(({id}) => id === ids[i])
		
						const title = algo.title
						const url = `<../${title} [${ids[i]}].cpp>`

						fileDataStringified += `[L${i+1}](${url}) `
					}
					fileDataStringified += "| "
				}
				fileDataStringified += '\n'
			}

			const mdFilePath = path.join(__dirname, '..', '..', 'algorithms', 'stats', `algo-links.md`);
			await fs.writeFile(mdFilePath, fileDataStringified);

			resolve();

		} catch (err) {
			console.log(err);
			reject();
		}
	});
}

async function generateStats() {
	try {
		const startTime = Date.now();
		console.log(`[${new Date().toISOString()}]: Algo Stat Generation Started.`);

		const algos = await loadFromJSON()
		console.log('JSON size = ' + algos.length)

		await generateMDlinksFileForAlgos(algos)

		console.log(`[${new Date().toISOString()}]: Algo Stat Generation Completed.`);
		const endTime = Date.now();
		console.log(`Time Taken to Generate Algo stats = ${endTime - startTime} ms`);
	} catch (err) {
		console.log(err);
	}
}

generateStats();