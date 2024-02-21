class Solution {
public:
    int solve(vector<int>& nums, int i, bool isPos){
        if(i == nums.size())
            return 0;
        int sign = isPos ? 1 : -1;
        int include = sign*nums[i] + solve(nums, i+1, !isPos);
        int exclude = solve(nums, i+1, isPos);
        return max(include, exclude);
    }

    long long maxAlternatingSum(vector<int>& nums) { // Recursion, T.C.=O(2^n)
        return solve(nums, 0, true);
    }
};
// isPos = true -> +ive, isPos = false -> -ive