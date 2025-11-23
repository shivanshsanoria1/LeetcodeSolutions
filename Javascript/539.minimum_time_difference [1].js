/**
 * @param {string[]} timePoints
 * @return {number}
 */
var findMinDifference = function(timePoints) {
    timePoints.sort()

    const n = timePoints.length
    let minDiff = 24*60
    for(let i=0; i<n; i++){
        const hh1 = timePoints[i].substring(0, 2)
        const mm1 = timePoints[i].substring(3)
        const time1 = 60*parseInt(hh1) + parseInt(mm1)
        
        const hh2 = timePoints[(i+1) % n].substring(0, 2)
        const mm2 = timePoints[(i+1) % n].substring(3)
        const time2 = 60*parseInt(hh2) + parseInt(mm2)

        let diff = Math.abs(time1 - time2)
        if(diff > 12*60)
            diff = 24*60 - diff
        
        minDiff = Math.min(minDiff, diff)
    }

    return minDiff
};