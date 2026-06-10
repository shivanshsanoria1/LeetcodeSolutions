class Solution {
public:
    // T.C.=O(n^3), S.C.=O(1)
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        int minSum = INT_MAX;

        for(int i=0; i<n-2; i++)
            for(int j=i+1; j<n-1; j++)
            {
                if(nums[i] >= nums[j] || minSum <= nums[i] + nums[j])
                    continue;
                for(int k=j+1; k<n; k++)
                    if(nums[j] > nums[k])
                        minSum = min(minSum, nums[i] + nums[j] + nums[k]);
            }

        return minSum == INT_MAX ? -1 : minSum;
    }
};