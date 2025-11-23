/**
 * @param {string} date
 * @return {number}
 */
var dayOfYear = function(date) {
    return 1 + (new Date(date) - new Date(date.slice(0, 4))) / (1000*60*60*24);
};