/**
 * @param {number} n
 * @param {number} w
 * @param {number} maxWeight
 * @return {number}
 */
var maxContainers = function(n, w, maxWeight) {
    return Math.min(n*n, Math.floor(maxWeight / w))
};