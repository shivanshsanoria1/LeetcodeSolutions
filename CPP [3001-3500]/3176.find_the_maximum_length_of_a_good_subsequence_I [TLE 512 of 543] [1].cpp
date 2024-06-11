class Solution {
private:
    int solve(vector<int>& nums, int k, int i, int prev){
        if(i >= nums.size())
            return 0;
        if(k < 0)
            return 0;

        int exclude = solve(nums, k, i+1, prev);

        int include = 0; 
        if(prev == -1 || prev == nums[i])
            include = 1 + solve(nums, k, i+1, nums[i]);
        else if(k > 0)
            include = 1 + solve(nums, k-1, i+1, nums[i]);
        
        return max(include, exclude);
    }

public:
    // T.C.=O(2^n)
    // Recursion
    int maximumLength(vector<int>& nums, int k) {
        return solve(nums, k, 0, -1);
    }
};