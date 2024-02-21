class RandomizedSet {
private:
    unordered_map<int, int> mp; // val -> index
    vector<int> vec; // vec[index] = val

public:
    RandomizedSet() {
        mp.clear();
        vec.clear();
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) // val found in map
            return false;
        vec.push_back(val);
        mp[val] = vec.size() - 1; // val -> last index of vec
        return true;
    }
    
    bool remove(int val) {
        auto it = mp.find(val); // iterator to 'val' in map
        if(it == mp.end()) // val not found in map
            return false;
        int idx = it->second;
        // swap the values at index idx and last index
        swap(vec[idx], vec[vec.size() - 1]);
        mp[vec[idx]] = idx; // update the index of the swapped val in map
        vec.pop_back(); // remove val from vec
        mp.erase(it); // rmove val from map
        return true;
    }
    
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