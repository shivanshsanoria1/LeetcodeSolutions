class Solution {
public:
    int solve(vector<int>& nums, int i, int curr_xor)
    {
        if(i==nums.size())
            return curr_xor;
        int include= solve(nums,i+1,curr_xor^nums[i]); //including nums[i]
        int exclude= solve(nums,i+1,curr_xor); //excluding nums[i]
        return include + exclude;
    }
    
    int subsetXORSum(vector<int>& nums) {
        return solve(nums,0,0);
    }
};