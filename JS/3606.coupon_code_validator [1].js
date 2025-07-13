/**
 * @param {string[]} code
 * @param {string[]} businessLine
 * @param {boolean[]} isActive
 * @return {string[]}
 */
var validateCoupons = function(code, businessLine, isActive) {
    function isValidCode(idx){
        const s = code[idx]

        if(s.length === 0)
            return false
        
        for(const ch of s){
            if(ch >= 'a' && ch <= 'z')
                continue
            if(ch >= 'A' && ch <= 'Z')
                continue
            if(ch >= '0' && ch <= '9')
                continue
            if(ch === '_')
                continue

            return false
        }

        return true
    }

    function businessLineToInt(idx){
        const validBusinessLines = {
            'electronics': 0,
            'grocery': 1,
            'pharmacy': 2,
            'restaurant': 3
        }

        for(const [key, val] of Object.entries(validBusinessLines))
            if(businessLine[idx] === key)
                return val

        return -1
    }

    const idxs = []
    for(let i=0; i<code.length; i++){
        if(!isActive[i])
            continue
        if(!isValidCode(i))
            continue
        if(businessLineToInt(i) === -1)
            continue
        
        idxs.push(i)
    }

    idxs.sort((i, j) => {
        function lexicographical_cmp(i, j){
            const s1 = code[i]
            const s2 = code[j]

            if(s1 < s2) return -1
            if(s1 > s2) return 1
            return 0
        }

        return businessLine[i] === businessLine[j] ? lexicographical_cmp(i, j) : businessLineToInt(i) - businessLineToInt(j)
    })

    const ans = []
    for(const idx of idxs)
        ans.push(code[idx])
    
    return ans
};