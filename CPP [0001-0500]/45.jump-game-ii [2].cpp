class Solution {
public:
    int jump(vector<int>& nums) { // DP
        int n= nums.size();
        vector<int> dp(n, 0);
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<=i+nums[i] && j<n; j++)
            {
                if(dp[j]==0)
                    dp[j]= dp[i]+1;
                if(dp[n-1] > 0)
                    return dp[n-1];
            }
        return 0;
    }
};