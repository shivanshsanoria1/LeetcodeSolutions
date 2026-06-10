class Skiplist {
private:
    // { num, freq }
    vector<pair<int, int>> mp;

public:
    Skiplist() {
        this->mp.clear();
    }
    
    // T.C.=O(n)
    bool search(int target) {
        for(auto [num, freq]: mp)
            if(num == target)
                return true;

        return false;
    }
    
    // T.C.=O(n)
    void add(int num) {
        for(auto& [val, freq]: mp)
            if(val == num)
            {
                freq++;
                return;
            }

        mp.push_back({num, 1});
    }
    
    // T.C.=O(n)
    bool erase(int num) {
        for(int i=0; i<mp.size(); i++)
        {
            if(mp[i].first != num)
                continue;

            mp[i].second--;

            if(mp[i].second == 0)
            {
                for(int j=i; j<mp.size()-1; j++)
                    mp[j] = mp[j+1];
                mp.pop_back();
            }

            return true;
        }

        return false;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */