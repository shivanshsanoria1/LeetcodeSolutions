class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // DP: Tabulation
    long long rob(vector<int>& nums, vector<int>& colors) {
        const int n = nums.size();
        vector<long long int> dp(n, -1);
        
        for(int i=0; i<n; i++){
            long long int prev2 = i-2 >= 0 ? dp[i-2] : 0;
            long long int prev1 = i-1 >= 0 ? dp[i-1] : 0;

            if(i-1 >= 0 && colors[i-1] == colors[i])
                dp[i] = max(prev1, nums[i] + prev2);
            else
                dp[i] = nums[i] + max(prev1, prev2);
        }
            
        return dp[n-1];
    }
};

// prerequisite: 198.house-robber