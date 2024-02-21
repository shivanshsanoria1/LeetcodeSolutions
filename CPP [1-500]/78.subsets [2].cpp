class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) { // Bit manipulation
        int n=nums.size();
        vector<vector<int>> subsets;
        for(int i=0; i < (1 << n); i++) // each iteration generates a subset
        {
            vector<int> subset;
            for(int j=0; j<n; j++)
                if(i & 1 << j)
                    subset.push_back(nums[j]);
            subsets.push_back(subset);
        }
        return subsets;
    }
};
// (1 << n) is same as pow(2, n)