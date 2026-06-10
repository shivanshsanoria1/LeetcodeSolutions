/**
 * @param {any} object
 * @param {any} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if(obj === null || obj === undefined || typeof classFunction !== 'function')
        return false;
    return Object(obj) instanceof classFunction;
    /* Primitives are not objects and do not have properties or methods, so the instanceof operator 
    returns false when we use it with a primitive. We have to convert the primitive value into Object 
    to use instanceof operator. 
    In Javascript, we can convert every thing into object and when we convert null or undefined 
    if will become a instance of Object class, so it is important to make sure the object isn't one of those.*/
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */