/**
 * @param {number[]} cost
 * @return {number[]}
 */
var minCosts = function(cost) {
    const ans = []
    let minCost = 100
    
    for(const currCost of cost){
        minCost = Math.min(minCost, currCost)
        ans.push(minCost)
    }

    return ans
};