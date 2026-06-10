class Solution {
public:
    string destCity(vector<vector<string>>& paths) { // T.C.=O(n), S.C.=O(n)
        unordered_map<string, bool> mp; // city -> source or destination
        for(auto path: paths)
        {
            mp[path[0]] = false; // add source
            if(mp.find(path[1]) == mp.end()) // destination not found in map
                mp[path[1]] = true; // add destination
        }
        for(auto it: mp)
            if(it.second) // destination found
                return it.first;
        return "";
    }
};
// false: source, true: destination