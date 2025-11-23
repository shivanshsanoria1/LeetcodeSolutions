/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(rowsCount, colsCount) {
    const nums = this;
    const m = rowsCount, n = colsCount;
    if(m*n !== nums.length)
        return [];
    // m*n matrix filled with 0's
    const matrix = new Array(m).fill(0).map(() => new Array(n).fill(0));
    let k = 0;
    for(let j=0; j<n; j++){
        if(j % 2 === 0){
            for(let i=0; i<m; i++){
                matrix[i][j] = nums[k];
                k++;
            }
        }else{
            for(let i=m-1; i>=0; i--){
                matrix[i][j] = nums[k];
                k++;
            }
        }
    }
    return matrix;
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */