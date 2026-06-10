class SnapshotArray {
private:
    vector<int> arr;
    vector<vector<int>> snaps;

public:
    SnapshotArray(int length) {
        arr.resize(length);
    }
    
    void set(int index, int val) {
        arr[index] = val;
    }
    
    int snap() {
        snaps.push_back(arr);
        return snaps.size()-1;
    }
    
    int get(int index, int snap_id) {
        return snaps[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */