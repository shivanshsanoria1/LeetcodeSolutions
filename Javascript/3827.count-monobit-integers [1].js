/**
 * @param {number} n
 * @return {number}
 */
var countMonobit = function(n) {
    return 1 + Math.floor(Math.log2(n+1))
};

// every monobit int is of the form (2^n - 1), n=0,1,2,...