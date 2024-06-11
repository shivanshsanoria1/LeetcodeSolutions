class Solution {
private:
    typedef vector<int> VEC1D;
    typedef vector<vector<int>> VEC2D;
    typedef vector<vector<vector<int>>> VEC3D;

    int solve(vector<int>& nums, int k, int i, int prevIdx, VEC3D& dp){
        if(i >= nums.size())
            return 0;
        if(k < 0)
            return 0;

        if(dp[i][prevIdx + 1][k] != -1)
            return dp[i][prevIdx + 1][k];

        int exclude = solve(nums, k, i+1, prevIdx, dp);

        int include = 0; 
        if(prevIdx == -1 || nums[prevIdx] == nums[i])
            include = 1 + solve(nums, k, i+1, i, dp);
        else if(k > 0)
            include = 1 + solve(nums, k-1, i+1, i, dp);
        
        dp[i][prevIdx + 1][k] = max(include, exclude);

        return dp[i][prevIdx + 1][k]; 
    }

public:
    // T.C.=O(k*n^2), S.C.=O(k*n^2)
    // DP-Memoization
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        VEC3D dp(n, VEC2D(n+1, VEC1D(k+1, -1)));

        return solve(nums, k, 0, -1, dp);
    }
};