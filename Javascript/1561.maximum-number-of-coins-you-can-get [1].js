/**
 * @param {number[]} piles
 * @return {number}
 */
var maxCoins = function(piles) {
    piles.sort((a, b) => a-b)

    let sum = 0
    for(let i=0, j=piles.length-1; i<j; i++, j-=2)
        sum += piles[j-1]

    return sum
};