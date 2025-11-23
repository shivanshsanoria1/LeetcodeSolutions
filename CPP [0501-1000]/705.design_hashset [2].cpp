class MyHashSet {
// Time efficient and Space inefficient soln.
private:
    // set[i] = false indicates i is not present in set
    // set[i] = true indicates i is present in set
    vector<bool> set;

public:
    MyHashSet() {
        set.resize(1000001, false); // set of size 1,000,001 filled with false's
    }
    
    void add(int key) { // T.C.=O(1)
        set[key] = true;
    }
    
    void remove(int key) { // T.C.=O(1)
        set[key] = false;
    }
    
    bool contains(int key) { // T.C.=O(1)
        return set[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */