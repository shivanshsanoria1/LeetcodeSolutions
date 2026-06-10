class Solution {
private:
    int solve(vector<int>& nums, int i, int x){
        if(i == nums.size())
            return x;

        int include = solve(nums, i+1, x ^ nums[i]);
        int exclude = solve(nums, i+1, x);

        return include + exclude;
    }

public:   
    // T.C.=O(2^n), S.C.=O(n)
    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};