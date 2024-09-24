var TimeLimitedCache = function() {
    // key -> {value, duration, createdAt}
    this.mp = new Map()
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const isFound = this.mp.has(key)

    this.mp.set(key, {value, duration, createdAt: Date.now()})

    return isFound
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    // key not found in map
    if(!this.mp.has(key)){
        return -1
    }

    const {value, duration, createdAt} = this.mp.get(key)

    // key is expired, so remove it from map
    if(createdAt + duration < Date.now()){
        this.mp.delete(key)
        return -1
    }

    return value
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    let unExpKeys = 0 // unexpired keys

    for(const [key, obj] of this.mp){
        const {duration, createdAt} = obj

        // key is expired, so remove it from map
        if(createdAt + duration < Date.now()){
            this.mp.delete(key)
        }else{ // key is not expired at the moment
            unExpKeys++
        }
    }

    return unExpKeys
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */