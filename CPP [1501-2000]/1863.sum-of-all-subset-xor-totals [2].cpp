class Solution {
private:
    int solve(vector<int>& nums, vector<int>& subset, int i){
        if(i == nums.size())
        {
            int x = 0;
            for(int num: subset)
                x = x^num; 
            return x;
        }

        // exclude nums[i]
        int exclude = solve(nums, subset, i+1);

        // include nums[i]
        subset.push_back(nums[i]);
        int include = solve(nums, subset, i+1); 
        subset.pop_back();

        return exclude + include;
    }

public:
    // T.C.=O(n * 2^n), S.C.=O(n)
    int subsetXORSum(vector<int>& nums) {
        vector<int> subset;
        return solve(nums, subset, 0);
    }
};