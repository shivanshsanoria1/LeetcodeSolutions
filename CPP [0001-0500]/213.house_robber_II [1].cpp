class Solution {
public:
    int rob1(vector<int>& nums, int start, int end)
    {
        int prev2=0, prev1=0; //prev2 ~ dp[i-2] , prev1 ~ dp[i-1]
        int curr;
        for(int i=start; i<=end; i++)
        {
            curr = max(prev1, nums[i] + prev2);
            prev2=prev1; //move prev2 forward
            prev1=curr; //move prev1 forward
        }
        return prev1;
    }
    
    int rob(vector<int>& nums) { //T.C.=O(n) , S.C.=O(1) ; DP (optimized)
        int n=nums.size();
        if(n==0) //no house to rob
            return 0;
        if(n==1) //only 1 house to rob
            return nums[0];
        return max(rob1(nums,0,n-2), rob1(nums,1,n-1));
    }
};
// using the code from Leetcode-198 (house robber)