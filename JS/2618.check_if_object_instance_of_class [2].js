/**
 * @param {any} object
 * @param {any} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if(obj === null || obj === undefined)
        return false;
    // get the prototype of obj
    let proto = Object.getPrototypeOf(obj); 
    // iterate through the prototype chain
    while(proto !== null){
        // check if the prototype's constructor is equal to the class function
        if(proto.constructor === classFunction)
            return true;
        // get the next prototype in the chain
        proto = Object.getPrototypeOf(proto);
    }
    return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */