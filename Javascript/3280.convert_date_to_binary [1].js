/**
 * @param {string} date
 * @return {string}
 */
var convertDateToBinary = function(date) {
    const [yyyy, mm, dd] = date.split('-')

    return `${parseInt(yyyy).toString(2)}-${parseInt(mm).toString(2)}-${parseInt(dd).toString(2)}`
};