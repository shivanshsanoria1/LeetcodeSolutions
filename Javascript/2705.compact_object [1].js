/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    const res = Array.isArray(obj) ? [] : {}

    for(const key in obj){
        const ele = obj[key]

        if(!Boolean(ele))
            continue
        
        if(Array.isArray(ele)){
            if(Array.isArray(res))
                res.push([...compactObject(ele)])
            else
                res[key] = [...compactObject(ele)]

        }else if(typeof ele === 'object'){
            if(Array.isArray(res))
                res.push({...compactObject(ele)})
            else
                res[key] = {...compactObject(ele)}
                
        }else{
            if(Array.isArray(res))
                res.push(ele)
            else
                res[key] = ele
        }

    }

    return res
};