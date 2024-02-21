class NumberContainers {
private:
    unordered_map<int, int> mp1; // index -> num
    unordered_map<int, set<int>> mp2; // num -> {index}

public:
    NumberContainers() {
        mp1.clear();
        mp2.clear();
    }
    
    void change(int index, int number) {
        if(mp1.find(index) != mp1.end()) // 'index' already exists
        {
            // old number corresponding to 'index'
            int oldNum = mp1[index];
            // remove the index corresponding to the old number
            mp2[oldNum].erase(index);
            // remove old number from the map2 if it does not have 
            // any corresponding index remaining
            if(mp2[oldNum].empty())
                mp2.erase(oldNum);
        }
        // update 'index' with the new number
        mp1[index] = number;
        // add the new number with its index in map2
        mp2[number].insert(index);
    }
    
    int find(int number) {
        return mp2.find(number) != mp2.end() ? *mp2[number].begin() : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */