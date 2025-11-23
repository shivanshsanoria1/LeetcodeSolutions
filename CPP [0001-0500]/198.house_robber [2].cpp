class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // DP-Tabulation with Space-Optimization
    int rob(vector<int>& nums) { 
        // prev2 ~ dp[i-2] , prev1 ~ dp[i-1]
        int prev2 = 0, prev1 = 0; 

        for(int num: nums)
        {
            int curr = max(prev1, num + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};