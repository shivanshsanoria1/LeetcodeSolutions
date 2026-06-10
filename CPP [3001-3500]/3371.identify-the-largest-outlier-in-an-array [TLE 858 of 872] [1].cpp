class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int getLargestOutlier(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int maxOutlier = -1001;

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
            {
                // nums[i]: special sum, nums[j]: outlier
                if(totalSum - nums[i] - nums[j] == nums[i])
                    maxOutlier = max(maxOutlier, nums[j]);
                // nums[i]: outlier, nums[j]: special sum
                if(totalSum - nums[j] - nums[i] == nums[j])
                    maxOutlier = max(maxOutlier, nums[i]);
            }

        return maxOutlier;
    }
};

/*
# let, nums[i]: special sum, nums[j]: outlier
# then, totalSum - nums[i] - nums[j] == nums[i]
*/