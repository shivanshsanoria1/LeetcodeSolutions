class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    // DP: Tabulation
    int lengthOfLIS(vector<int>& nums) { 
        int n = nums.size();
        vector<int> dp(n, 1);

        for(int i=1; i<n; i++)
            for(int prevIdx = 0; prevIdx < i; prevIdx++)
                if(nums[prevIdx] < nums[i])
                    dp[i] = max(dp[i], 1 + dp[prevIdx]);

        return *max_element(dp.begin(), dp.end());
    }
};

// dp[i]: the length of LIS ending at index i
// initially dp[i] = 1, since the length of LIS 
// starting and ending at index i is 1