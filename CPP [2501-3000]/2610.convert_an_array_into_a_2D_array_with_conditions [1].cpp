class Solution {
public:
    // S.C.=O(n)
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp; // num -> freq
        for(int num: nums)
            mp[num]++;

        vector<vector<int>> grid;
        while(true)
        {
            vector<int> row;
            for(auto& [num, freq]: mp)
                if(freq > 0)
                {
                    row.push_back(num);
                    freq--;
                }
                
            if(row.empty())
                break;
            grid.push_back(row);
        }
        return grid;
    }
};