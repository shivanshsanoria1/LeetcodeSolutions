/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    const mp = new Map();

    // push all objects and their id's from arr1 into map
    for(const obj of arr1){
        mp.set(obj.id, obj);
    }

    for(const obj2 of arr2){
        // obj2.id found in map
        if(mp.has(obj2.id)){
            // get the obj1 corresponding to the obj2 id
            const obj1 = mp.get(obj2.id);
            // add the keys from obj2 into obj1
            // thus replacing all the key from obj1 with the ones found in obj2 
            for(const key of Object.keys(obj2)){
                obj1[key] = obj2[key];
            }
        }else{
            mp.set(obj2.id, obj2);
        }
    }

    const arr = [];
    // push all the values from map to the final array
    for(const key of mp.keys()){ 
        arr.push(mp.get(key));
    }
    // sort the final array in increasing order of id's
    arr.sort((a, b) => a.id - b.id);
    return arr;
};