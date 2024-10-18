class Solution {
private:
    int solve(vector<int>& nums, int i, vector<int>& subset, int maxBitwiseOR){
        if(i == nums.size())
        {
            int bitwiseOR = 0;
            for(int num: subset)
                bitwiseOR |= num;

            return bitwiseOR == maxBitwiseOR ? 1 : 0;
        }
        
        int exclude = solve(nums, i+1, subset, maxBitwiseOR);

        subset.push_back(nums[i]);
        int include = solve(nums, i+1, subset, maxBitwiseOR);
        subset.pop_back();

        return exclude + include;
    }

public:
    // T.C.=O(n*2^n), S.C.=O(n)
    // Backtracking
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> subset;
        int maxBitwiseOR = 0;
        for(int num: nums)
            maxBitwiseOR |= num;

        return solve(nums, 0, subset, maxBitwiseOR);
    }
};

// max possible bitwise-OR is the bitwise-OR of entire array