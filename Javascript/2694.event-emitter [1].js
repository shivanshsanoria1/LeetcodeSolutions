class EventEmitter {
    constructor(){
        this.eventMap = {}; // event -> set of callbacks
    }

    subscribe(event, cb) {
        if(!this.eventMap[event]) // event does not exist in map
            this.eventMap[event] = new Set(); // add the event mapped with an empty set
        this.eventMap[event].add(cb); // add the callback to the set of the curr event

        return {
            unsubscribe: () => {
                // delete the callback from the set of the curr event
                this.eventMap[event].delete(cb);
            }
        };
    }

    emit(event, args = []) {
        const ans = [];
        if(!this.eventMap[event]){ // event does not exist in map
            return ans;
        }
        // execute each callback for the curr event and 
        // push the results of those callbacks in the ans array
        this.eventMap[event].forEach((cb) => ans.push(cb(...args)));
        return ans;
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */