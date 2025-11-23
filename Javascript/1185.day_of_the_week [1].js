/**
 * @param {number} day
 * @param {number} month
 * @param {number} year
 * @return {string}
 */
var dayOfTheWeek = function(day, month, year) {
    // -1 is added in month as month is 0-indexed
    const dayNum = new Date(year, month - 1, day).getDay()

    const dayNames = [
        "Sunday", "Monday", "Tuesday", "Wednesday", 
        "Thursday", "Friday", "Saturday"
    ]

    return dayNames[dayNum]
};