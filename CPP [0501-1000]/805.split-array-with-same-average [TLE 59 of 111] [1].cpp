class Solution {
private:
    bool solve(vector<int>& nums, int i, int totalSum, int& sum, int& includedCount){
        int n=nums.size();
        if((double)sum/includedCount == (double)(totalSum - sum)/(n - includedCount))
            return true;

        if(i >= n)
            return false;

        bool exclude = solve(nums, i+1, totalSum, sum, includedCount);
        if(exclude)
            return exclude;

        sum += nums[i];
        includedCount++;
        bool include = solve(nums, i+1, totalSum, sum, includedCount);
        sum -= nums[i];
        includedCount--;

        return include;
    }

public:
    // T.C.=O(2^n), S.C.=O(n)
    // Backtracking
    bool splitArraySameAverage(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        int includedCount = 0;
        
        return solve(nums, 0, totalSum, sum, includedCount);
    }
};