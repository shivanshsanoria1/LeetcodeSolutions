const path = require("path");
const fs = require("fs");

const config = Object.freeze(require("./config.json"));

const ROOT = path.resolve(__dirname, "..");

function getPath(section, key) {
	const relPath = config[section]?.[key];

	if (!relPath) {
		throw new Error(`Unknown ${section} key: ${key}`);
	}

	return path.resolve(ROOT, relPath);
}

const getRootRelativePath = (filePath) => path.relative(ROOT, filePath);

const getDirPath = (key) => getPath("dirPaths", key);
const getFilePath = (key) => getPath("filePaths", key);

function ensureDir(key) {
	const dir = getDirPath(key);
	fs.mkdirSync(dir, { recursive: true });
	return dir;
}

function ensureFileDir(key) {
	const file = getFilePath(key);
	fs.mkdirSync(path.dirname(file), { recursive: true });
	return file;
}

module.exports = {
	ROOT,
	getDirPath,
	getFilePath,
	ensureDir,
	ensureFileDir,
	getRootRelativePath
};