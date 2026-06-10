class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) { // T.C.=O(m*nlogn), S.C.=O(1)
        int m = nums.size(), n = nums[0].size();
        for(int i=0; i<m; i++)
            sort(nums[i].begin(), nums[i].end()); // sort each row
        int ans=0;
        for(int j=0; j<n; j++)
        {
            int maxInCol = 0;
            for(int i=0; i<m; i++)
                maxInCol = max(maxInCol, nums[i][j]);
            ans += maxInCol;
        }
        return ans;
    }
};