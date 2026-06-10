class Solution {
public:
    bool solve(vector<int>& nums, int i){
        int n=nums.size();
        if(i == n)
            return true;
        bool cond1 = i+1 < n && nums[i] == nums[i+1];
        bool cond2 = i+2 < n && nums[i] == nums[i+1] && nums[i] == nums[i+2];
        bool cond3 = i+2 < n && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1;
        if(cond1 && solve(nums, i+2))
            return true;
        if((cond2 || cond3) && solve(nums, i+3))
            return true;
        return false;
    }

    bool validPartition(vector<int>& nums) { // Recursion
        return solve(nums, 0);
    }
};