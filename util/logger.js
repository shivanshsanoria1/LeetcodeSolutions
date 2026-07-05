const fs = require('fs');
const path = require('path');
const util = require('util');

const timer = require('./timer.js')

const LOG_DIR = path.resolve(__dirname, 'logs');

const STATE = {
	errorFound: false
}

function ensureLogDir() {
	try {
		fs.mkdirSync(LOG_DIR, { recursive: true });
	} catch (err) {
		throw new Error(`Failed to create log directory: ${err.message}`);
	}
}

function getLogFilePath() {
	const now = new Date();
	const year = now.getFullYear();
	const month = String(now.getMonth() + 1).padStart(2, '0');
	const day = String(now.getDate()).padStart(2, '0');

	const fileName = `logs_${year}-${month}-${day}.log`;

	return path.join(LOG_DIR, fileName);
}

function writeLine(line) {
	const filePath = getLogFilePath();

	try {
		fs.appendFileSync(filePath, line + '\n', { encoding: 'utf8' });
	} catch (err) {
		console.error(`Failed to write to log file (${filePath}): ${err.message}`);
	}
}

function serialize(payload) {
	if (typeof payload === 'string') {
		return payload;
	}

	return util.inspect(payload, {
		depth: null,
		colors: false,
		compact: false,
		breakLength: Infinity,
		maxArrayLength: null,
		maxStringLength: null
	});
}

function write(level, data) {
	ensureLogDir();

	const message = serialize(data);
	const line = `[${timer.getTimestamp()}] [${level}] ${message}`;

	writeLine(line);
}

function info(data) {
	write('INFO', data);
}

function error(data) {
	write('ERROR', data);
	STATE.errorFound = true
}

function time(msg) {
	console.log(`[${timer.getTimestamp()}]: ${msg}`);
	write('INFO', msg);
}

module.exports = {
	info,
	error,
	time,
	STATE
};
