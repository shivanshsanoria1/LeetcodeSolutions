class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& subsets, vector<int>& subset, int i){
        if(i == nums.size())
        {
            subsets.push_back(subset);
            return;
        }

        // exclude nums[i]
        solve(nums, subsets, subset, i+1);

        // include nums[i]
        subset.push_back(nums[i]);
        solve(nums, subsets, subset, i+1); 
        subset.pop_back();
    }

public:
    // T.C.=O(n * 2^n), S.C.=O(n * 2^n)
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        solve(nums, subsets, subset, 0);

        int sum = 0;
        for(vector<int>& subset: subsets)
        {
            int x = 0;
            for(int num: subset)
                x = x^num; 
            sum += x;
        }
        return sum;
    }
};