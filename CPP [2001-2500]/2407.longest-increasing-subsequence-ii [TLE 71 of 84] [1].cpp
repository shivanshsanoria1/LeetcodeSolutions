class Solution {
private:
    int solve(vector<int>& nums, int k, int prevIdx, int currIdx){
        int n=nums.size();
        if(currIdx == n)
            return 0;

        int res = 0;
        for(int i=currIdx; i<n; i++)
        {
            // excluding the element at index i 
            res = max(res, solve(nums, k, prevIdx, i+1));
            // including the element at index i 
            if(prevIdx == -1 || (nums[i] > nums[prevIdx] && nums[i] - nums[prevIdx] <= k))
                res = max(res, 1 + solve(nums, k, i, i+1));
        }

        return res; 
    }

public:
    // Recursion
    int lengthOfLIS(vector<int>& nums, int k) {
        return solve(nums, k, -1, 0);
    }
};