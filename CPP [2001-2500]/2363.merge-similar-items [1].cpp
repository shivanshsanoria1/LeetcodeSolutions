class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp; // value -> weight
        for(auto& item: items1)
            mp[item[0]] = item[1];
        for(auto& item: items2)
            mp[item[0]] += item[1];
        vector<vector<int>> ans;
        for(auto it: mp)
            ans.push_back({it.first, it.second});
        return ans;
    }
};
// T.C.=O((n1 + n2)log(n1 + n2)), S.C.=O(n1 + n2) 