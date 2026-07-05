const fs = require('fs');
const path = require('path');
const util = require('util');

const LOG_DIR = path.resolve(__dirname, 'logs');

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

// gives the local timestamp by default, use 'ISO' to get the ISOString
function getTimestamp(zone = 'local') {
	const now = new Date();

	if (String(zone).toUpperCase() === 'ISO') {
		return now.toISOString();
	}

	// Local system time
	const pad = (n) => String(n).padStart(2, "0");

	return (
		`${now.getFullYear()}-` +
		`${pad(now.getMonth() + 1)}-` +
		`${pad(now.getDate())}T` +
		`${pad(now.getHours())}:` +
		`${pad(now.getMinutes())}:` +
		`${pad(now.getSeconds())}.` +
		`${String(now.getMilliseconds()).padStart(3, "0")}`
	);
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
	const line = `[${getTimestamp()}] [${level}] ${message}`;

	writeLine(line);
}

function info(data) {
	write('INFO', data);
}

function error(data) {
	write('ERROR', data);
}

function time(msg) {
	console.log(`[${getTimestamp()}]: ${msg}`);
	write('INFO', msg);
}

module.exports = { info, error, time };
