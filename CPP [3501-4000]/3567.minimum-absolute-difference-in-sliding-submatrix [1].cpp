class Solution {
private:
    // returns the min abs diff between any 2 elements in the 
    // square submatrix of size k with top-left corner at (x1, y1)
    int findMinAbsDiff(vector<vector<int>>& grid, int x1, int y1, int k){
        vector<int> nums;
        for(int i=x1; i < x1+k; i++)
            for(int j=y1; j < y1+k; j++)
                nums.push_back(grid[i][j]);

        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;
        for(int i=1; i<nums.size(); i++)
            if(nums[i-1] != nums[i])
                minDiff = min(minDiff, nums[i] - nums[i-1]);
        
        return minDiff == INT_MAX ? 0 : minDiff;
    }

public:
    // T.C.=O(m*n* (k^2)*log(k^2)), S.C.=O(k^2)
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1, 0));
        for(int i=0; i < m-k+1; i++)
            for(int j=0; j < n-k+1; j++)
                ans[i][j] = findMinAbsDiff(grid, i, j, k);

        return ans;
    }
};