/**
 * @param {string[]} timePoints
 * @return {number}
 */
var findMinDifference = function(timePoints) {
    const s = new Set(timePoints)
    // presence of duplicate items mean min-diff is 0
    if(s.size != timePoints.length)
        return 0
    
    const times = []
    for(const hhmm of s){
        const hh = hhmm.substring(0, 2)
        const mm = hhmm.substring(3)
        const time = 60*parseInt(hh) + parseInt(mm)

        times.push(time)
    }

    times.sort((a, b) => a - b)

    const m = times.length
    let minDiff = 24*60
    for(let i=0; i<m; i++){
        let diff = Math.abs(times[(i+1) % m] - times[i])
        if(diff > 12*60)
            diff = 24*60 - diff

        minDiff = Math.min(minDiff, diff)
    }

    return minDiff
};