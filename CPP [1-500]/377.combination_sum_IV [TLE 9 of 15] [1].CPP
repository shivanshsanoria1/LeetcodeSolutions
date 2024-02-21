class Solution {
public:
    int solve(vector<int>& nums, int tar){
        if(tar < 0)
            return 0;
        if(tar == 0)
            return 1;
        int sum = 0;
        for(int num: nums)
            sum += solve(nums, tar-num);
        return sum;
    }

    int combinationSum4(vector<int>& nums, int target) { // Recursion
        return solve(nums, target);
    }
};