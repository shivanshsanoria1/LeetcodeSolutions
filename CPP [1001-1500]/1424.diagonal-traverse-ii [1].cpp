class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) { // T.C.=O(m*n), S.C.=O(m*n)
        int maxC = 0;
        for(int i=0; i<nums.size(); i++)
            maxC = max(maxC, (int)nums[i].size());

        vector<vector<int>> mp(nums.size() + maxC - 1);
        for(int i=0; i<nums.size(); i++)
            for(int j=0; j<nums[i].size(); j++)
                mp[i + j].push_back(nums[i][j]);

        vector<int> ans;
        for(int i=0; i<mp.size(); i++)
            for(int j=mp[i].size()-1; j>=0; j--)
                ans.push_back(mp[i][j]);
                
        return ans;
    }
};
// m: num of rows, n: max num of cols in any row