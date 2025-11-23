class RandomizedSet {
private:
    // val -> index
    unordered_map<int, int> mp; 
    // vec[index] = val
    vector<int> vec; 

public:
    RandomizedSet() {
        // set the seed to be used by rand()
        // to generate random nums
        srand(time(0));

        this->mp.clear();
        this->vec.clear();
    }
    
    // T.C.=O(1)
    bool insert(int val) {
        // val found in map
        if(mp.find(val) != mp.end()) 
            return false;

        vec.push_back(val);
        // val -> last index of vec
        mp[val] = vec.size() - 1; 

        return true;
    }
    
    // T.C.=O(1)
    bool remove(int val) {
        // iterator to 'val' in map
        auto itr = mp.find(val); 
        // 'val' not found in map
        if(itr == mp.end()) 
            return false;

        // index of the value to be removed
        int idx = itr->second;
        // swap the values at index 'idx' and last index
        swap(vec[idx], vec[vec.size() - 1]);
        // update the index of the swapped val in map
        mp[vec[idx]] = idx;
        // remove 'val' from vec
        vec.pop_back();
        // remove 'val' from map 
        mp.erase(itr); 

        return true;
    }
    
    // T.C.=O(1)
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */