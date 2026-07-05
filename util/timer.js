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

function getYYYYMMDD() {
	const now = new Date();

	const year = now.getFullYear();
	const month = String(now.getMonth() + 1).padStart(2, '0');
	const day = String(now.getDate()).padStart(2, '0');

	return `${year}-${month}-${day}`;
}

module.exports = {
	getTimestamp,
	getYYYYMMDD
}