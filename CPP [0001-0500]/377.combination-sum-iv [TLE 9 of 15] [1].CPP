class Solution {
private:
    int solve(vector<int>& nums, int tar){
        if(tar < 0)
            return 0;
        if(tar == 0)
            return 1;

        int sum = 0;
        for(int num: nums)
            sum += solve(nums, tar - num);

        return sum;
    }

public:
    // Recursion
    int combinationSum4(vector<int>& nums, int target) { 
        return solve(nums, target);
    }
};