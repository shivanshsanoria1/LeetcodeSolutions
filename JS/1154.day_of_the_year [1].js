/**
 * @param {string} date
 * @return {number}
 */
var dayOfYear = function(date) {
    const d = new Date(date);
    const yyyy = d.getFullYear();
    const mm = d.getMonth() + 1; // +1 is to convert 0-based to 1-based indexing
    const dd = d.getDate();

    const days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    if(new Date(yyyy, 1, 29).getDate() === 29) // leap year
        days[1]++;
    
    let ans = 0;
    for(let i=0; i<mm-1; i++)
        ans += days[i];
    return ans + dd;
};