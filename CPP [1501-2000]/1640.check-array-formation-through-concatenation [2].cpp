class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> mp; // num -> index
        for(int i=0; i<arr.size(); i++)
            mp[arr[i]] = i;

        for(int i=0; i<pieces.size(); i++)
        {
            if(mp.find(pieces[i][0]) == mp.end()) // not found in map
                return false;
            int idx = mp[pieces[i][0]];
            for(int j=1; j<pieces[i].size(); j++)
            {
                if(mp.find(pieces[i][j]) == mp.end()) // not found in map
                    return false;
                if(mp[pieces[i][j]] != idx + j) // wrong index
                    return false;
            }
        }
        return true;
    }
};