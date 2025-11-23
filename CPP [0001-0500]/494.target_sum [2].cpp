class Solution {
public:
    int solve(vector<int>& nums, vector<vector<int>>& dp, int target, int total_sum, int sum, int i)
    {
        if(i==nums.size())
        {
            if(sum == target)
                return 1;
            else
                return 0;
        }
        if(dp[i][sum + total_sum] != -1)
            return dp[i][sum + total_sum];
        int add = solve(nums,dp,target,total_sum,sum + nums[i],i+1);
        int subtract = solve(nums,dp,target,total_sum,sum - nums[i],i+1);
        dp[i][sum + total_sum] = add + subtract;
        return dp[i][sum + total_sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) { //memoization
        int n=nums.size(), total_sum=0;
        for(int i=0; i<n; i++)
            total_sum += nums[i];
        vector<vector<int>> dp(n,vector<int> (2*total_sum + 1,-1));
        return solve(nums,dp,target,total_sum,0,0);
    }
};