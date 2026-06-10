class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        long long int count = 0;

        for(int i=0; i<n; i++)
        {
            int maxVal = 0;
            int minVal = INT_MAX;

            for(int j=i; j<n; j++)
            {
                maxVal = max(maxVal, nums[j]);
                minVal = min(minVal, nums[j]);

                if(maxVal > maxK || minVal < minK)
                    break;
                else if(maxVal == maxK && minVal == minK)
                    count++;
            }
        }

        return count;
    }
};