/**
 * @param {string} date
 * @return {string}
 */

function getMonthNum(monthStr){
    const months = [
        {name: 'Jan', val: '01'},
        {name: 'Feb', val: '02'},
        {name: 'Mar', val: '03'},
        {name: 'Apr', val: '04'},
        {name: 'May', val: '05'},
        {name: 'Jun', val: '06'},
        {name: 'Jul', val: '07'},
        {name: 'Aug', val: '08'},
        {name: 'Sep', val: '09'},
        {name: 'Oct', val: '10'},
        {name: 'Nov', val: '11'},
        {name: 'Dec', val: '12'}
    ]

    return months.find(({name}) => name === monthStr).val
}

var reformatDate = function(date) {
    const len = date.length
    
    const dd = len == 12 ? '0' + date.substring(0, 1) : date.substring(0, 2)
    const mm = len == 12 ? getMonthNum(date.substring(4, 7)) : getMonthNum(date.substring(5, 8))
    const yyyy = len == 12 ? date.substring(8) : date.substring(9)

    return yyyy + '-' + mm + '-' + dd
};