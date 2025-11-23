class Solution {
public:
    // T.C.=O(n * 2^n), S.C.=O(n)
    // Bit-manipulation
    vector<vector<int>> subsets(vector<int>& nums) { 
        int n=nums.size();
        vector<vector<int>> subsets;
        // generate all nums in range [0, 2^n) 
        // corresponding to each subset
        for(int mask = 0; mask < (1 << n); mask++) 
        {
            vector<int> subset;

            for(int i=0; i<n; i++)
                if(mask & (1 << i))
                    subset.push_back(nums[i]);

            subsets.push_back(subset);
        }

        return subsets;
    }
};
// (1 << n) is same as pow(2, n)