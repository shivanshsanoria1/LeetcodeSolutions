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

    bool validPartition(vector<int>& nums) { // Tabulation, T.C.=O(n), S.C.=O(n)
        int n=nums.size();
        if(n == 2)
            return nums[0] == nums[1];
        vector<bool> dp(n, false);
        dp[0] = false;
        dp[1] = checkCond1(nums, 1);
        dp[2] = checkCond2(nums, 2) || checkCond3(nums, 2);
        for(int i=3; i<n; i++)
        {
            if(checkCond1(nums, i) && dp[i-2])
                dp[i] = dp[i-2];
            else if((checkCond2(nums, i) || checkCond3(nums, i)) && dp[i-3])
                dp[i] = dp[i-3];
        }
        return dp[n-1];
    }
};