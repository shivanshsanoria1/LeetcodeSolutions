var TimeLimitedCache = function() {
    // key -> {value, expirationFunc}
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

    if(isFound){
        clearTimeout(this.mp.get(key).expirationFunc)
    }

    this.mp.set(key, {
        value, 
        expirationFunc: setTimeout(() => this.mp.delete(key), duration)
    })

    return isFound
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    return this.mp.has(key) ? this.mp.get(key).value : -1
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    return this.mp.size
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */