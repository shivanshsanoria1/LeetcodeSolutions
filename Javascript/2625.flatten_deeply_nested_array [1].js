/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    const flattened = []

    function dfs(arr, n){
        if(n === -1){
            flattened.push(arr)
            return
        }

        for(const ele of arr){
            if(Array.isArray(ele)){
                dfs(ele, n-1)
            }else{
                flattened.push(ele)
            }
        }
    }

    dfs(arr, n)

    return flattened
};