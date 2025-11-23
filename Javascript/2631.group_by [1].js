/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    const ans = {};
    for(const ele of this){
        const key = fn(ele);
        if(ans[key]){
            ans[key].push(ele);
        }else{
            ans[key] = [ele];
        }
    }
    return ans;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */