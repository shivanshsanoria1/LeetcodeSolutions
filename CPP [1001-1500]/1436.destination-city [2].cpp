class Solution {
public:
    string destCity(vector<vector<string>>& paths) { // T.C.=O(n), S.C.=O(n)
        unordered_set<string> s;
        for(auto path: paths) // insert the destinations in the set
            s.insert(path[1]);
        for(auto path: paths) // remove the sources from the set 
            s.erase(path[0]);
        return *s.begin();
    }
};