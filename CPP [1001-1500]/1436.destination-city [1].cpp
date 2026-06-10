class Solution {
public:
    string destCity(vector<vector<string>>& paths) { // T.C.=O(n), S.C.=O(n)
        unordered_set<string> s; // source set
        for(auto path: paths) // insert the sources in the source set
            s.insert(path[0]);
        for(auto path: paths)
            if(s.find(path[1]) == s.end()) // destination not found in source set
                return path[1];
        return "";
    }
};