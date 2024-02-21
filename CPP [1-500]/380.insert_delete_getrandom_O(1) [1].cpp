class RandomizedSet {
private:
    unordered_map<int, int> mp1; // val -> id
    unordered_map<int, int> mp2; // id -> val
    int id;

public:
    RandomizedSet() {
        mp1.clear();
        mp2.clear();
        id = 0;
    }
    
    bool insert(int val) {
        if(mp1.find(val) != mp1.end()) // val found in map1
            return false;
        mp1[val] = id;
        mp2[id] = val;
        id++;
        return true;
    }
    
    bool remove(int val) {
        auto it1 = mp1.find(val); // iterator to 'val' in map1
        if(it1 == mp1.end()) // val not found in map1
            return false;
        int removeId = it1->second;
        auto it2 = mp2.find(removeId); // iterator to 'removeId' in map2
        mp1.erase(it1);
        mp2.erase(it2);
        return true;
    }
    
    int getRandom() {
        int randId = rand() % id;
        // keep generating new randIds until it is found in map
        while(mp2.find(randId) == mp2.end())
            randId = rand() % id;
        return mp2[randId];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */