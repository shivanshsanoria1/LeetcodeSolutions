/**
 * @param {Object} context
 * @param {any[]} args
 * @return {any}
 */
Function.prototype.callPolyfill = function(context, ...args) {
    // create an unique key for the 'context' obj
    // Symbols are immutable (cannot be changed) and are unique
    // Symbols are often used to add unique property keys to an object that won't collide with keys 
    const tempKey = Symbol();
    // add temp key and its value is the function on which callPolyfill is called upon
    context[tempKey] = this;
    // call the function with ...args and store the result in 'ans'
    const ans = context[tempKey](...args);
    // delete the temp key from the 'context' obj
    delete context[tempKey];
    return ans;
}

/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */