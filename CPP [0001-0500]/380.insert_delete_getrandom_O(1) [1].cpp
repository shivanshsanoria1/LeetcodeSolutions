class RandomizedSet {
private:
    // val -> id
    unordered_map<int, int> mp1; 
    // id -> val
    unordered_map<int, int> mp2;

    int id = 0;

public:
    RandomizedSet() {
        // set the seed to be used by rand()
        // to generate random nums
        srand(time(0));

        this->mp1.clear();
        this->mp2.clear();
        this->id = 0;
    }
    
    // T.C.=O(1)
    bool insert(int val) {
        // val found in map1
        if(mp1.find(val) != mp1.end()) 
            return false;
        
        mp1[val] = id;
        mp2[id] = val;
        id++;

        return true;
    }
    
    // T.C.=O(1)
    bool remove(int val) {
        // iterator to 'val' in map1
        auto itr1 = mp1.find(val); 
        // 'val' not found in map1
        if(itr1 == mp1.end()) 
            return false;

        int removeId = itr1->second;
        // iterator to the id to be removed in map2
        auto itr2 = mp2.find(removeId); 

        mp1.erase(itr1);
        mp2.erase(itr2);

        return true;
    }
    
    // T.C.=O(??)
    int getRandom() {
        int randId = rand() % id;

        // keep generating new randIds until it is found in map2
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