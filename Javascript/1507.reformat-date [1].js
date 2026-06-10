/**
 * @param {string} date
 * @return {string}
 */

function getMonthNum(monthStr){
    const months = [
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    ]

    const idx = (months.findIndex((month) => month === monthStr) + 1).toString()

    return idx.length == 1 ? '0' + idx : idx
}

var reformatDate = function(date) {
    const len = date.length
    
    const dd = len == 12 ? '0' + date.substring(0, 1) : date.substring(0, 2)
    const mm = len == 12 ? getMonthNum(date.substring(4, 7)) : getMonthNum(date.substring(5, 8))
    const yyyy = len == 12 ? date.substring(8) : date.substring(9)

    return yyyy + '-' + mm + '-' + dd
};