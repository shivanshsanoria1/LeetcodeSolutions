class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> mp; // val -> {index}
    vector<int> vec; // vec[index] = val

public:
    RandomizedCollection() {
        mp.clear();
        vec.clear();
    }
    
    bool insert(int val) {
        // initially assume val is not found in map
        bool notFound = true; 
        // val found in map
        if(mp.find(val) != mp.end()) 
            notFound = false;
        // push 'val' in vec[]
        vec.push_back(val);
        // push 'val' and its index in map
        mp[val].insert(vec.size() - 1);
        return notFound;
    }
    
    bool remove(int val) {
        // iterator to 'val' in map
        auto itr = mp.find(val);
        // val not found in map
        if(itr == mp.end()) 
            return false;
        // set of indexes of the value to be removed
        auto& u_set = itr->second;
        // index of 'val' in vec[]
        int idx = *(u_set.begin()); 
        // remove this index from set
        u_set.erase(idx); 
        // remove the entry with 'val' from map if set of indexes becomes empty
        if(u_set.empty()) 
            mp.erase(itr);
        // value to be removed is not at the end of vec[]
        if(idx != vec.size()-1)
        {
            // swap the values at index idx and last index
            swap(vec[idx], vec.back());
            // remove the old index of the swapped value
            mp[vec[idx]].erase(vec.size() - 1);
            // add the new index of the swapped value
            mp[vec[idx]].insert(idx);
        }
        // remove the last element from vec[]
        vec.pop_back();
        return true;
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */