class MyHashSet {
// Time inefficient and Space efficient soln.
private:
    vector<int> set;

public:
    MyHashSet() {
        set.clear();
    }
    
    void add(int key) { // T.C.=O(n)
        if(!contains(key)) // key not present in set
            set.push_back(key);
    }
    
    void remove(int key) { // T.C.=O(n)
        int idx = -1;
        for(int i=0; i<set.size(); i++) // find the index of key
            if(set[i] == key)
            {
                idx = i;
                break;
            }
        if(idx == -1) // key not found
            return;
        // move each element after the index idx to their prev index
        // element at index idx is lost
        for(int i=idx; i<set.size()-1; i++) 
            set[i] = set[i+1];
        set.pop_back(); // pop the last element from set
    }
    
    bool contains(int key) { // T.C.=O(n)
        for(int ele: set)
            if(ele == key)
                return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */