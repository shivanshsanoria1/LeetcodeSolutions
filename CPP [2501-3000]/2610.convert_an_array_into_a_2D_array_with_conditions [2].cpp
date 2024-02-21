class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp; // num -> freq
        vector<vector<int>> grid;
        for(int num: nums)
        {
            if(mp[num] == grid.size())
                grid.push_back({});
            grid[mp[num]].push_back(num);
            mp[num]++;
        }
        return grid;
    }
};