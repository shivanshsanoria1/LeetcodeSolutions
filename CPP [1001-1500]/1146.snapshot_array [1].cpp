class SnapshotArray {
private:
    vector<map<int, int>> snaps; // snaps[i] = map of {snapId, val}
    int snapId = 0;

public:
    SnapshotArray(int length) {
        snaps.resize(length);
        for(int i=0; i<length; i++) // snapId = 0 -> val = 0
            snaps[i][0] = 0;
    }
    
    void set(int index, int val) {
        snaps[index][snapId] = val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto& mp = snaps[index];
        if(mp.find(snap_id) == mp.end()) // snap_id not found in map
        {   // return the closest value less than the snap_id from the previous snapshots
            auto it = mp.upper_bound(snap_id);
            it--;
            return it->second;
        }
        return mp[snap_id];
    }
};

/*
# upper_bound(val) returns first element which is > val. If not, return end().
# lower_bound(val) returns first element which is >= val. If not, return end().
*/

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
