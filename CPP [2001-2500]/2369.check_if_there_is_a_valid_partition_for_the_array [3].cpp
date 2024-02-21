class Solution {
public:
    bool checkCond1(vector<int>& nums, int i){
        return nums[i-1] == nums[i];
    }

    bool checkCond2(vector<int>& nums, int i){
        return nums[i-1] == nums[i] && nums[i-2] == nums[i];
    }

    bool checkCond3(vector<int>& nums, int i){
        return nums[i] - nums[i-1] == 1 && nums[i-1] - nums[i-2] == 1;
    }

    bool validPartition(vector<int>& nums) { // Space optimized dp, T.C.=O(n), S.C.=O(1)
        int n=nums.size();
        if(n == 2)
            return nums[0] == nums[1];
        bool dp3 = false; // dp[i-3]
        bool dp2 = checkCond1(nums, 1); // dp[i-2]
        bool dp1 = checkCond2(nums, 2) || checkCond3(nums, 2); // dp[i-1]
        for(int i=3; i<n; i++)
        {
            bool dp = false;
            if(checkCond1(nums, i) && dp2)
                dp = dp2;
            else if((checkCond2(nums, i) || checkCond3(nums, i)) && dp3)
                dp = dp3;
                
            dp3 = dp2;
            dp2 = dp1;
            dp1 = dp;
        }
        return dp1;
    }
};