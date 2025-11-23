/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let f2=0, f1=1;
    yield f2;
    yield f1;
    while(true){
        let f = f2 + f1;
        yield f;
        f2 = f1;
        f1 = f;
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */