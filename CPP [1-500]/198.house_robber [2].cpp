class Solution {
public:
    int rob(vector<int>& nums) { // DP (optimized), T.C.=O(n), S.C.=O(1)
        int prev2=0, prev1=0; //prev2 ~ dp[i-2] , prev1 ~ dp[i-1]
        int curr;
        for(int i=0; i<nums.size(); i++)
        {
            curr = max(prev1, nums[i] + prev2);
            prev2=prev1; //move prev2 forward
            prev1=curr; //move prev1 forward
        }
        return prev1;
    }
};