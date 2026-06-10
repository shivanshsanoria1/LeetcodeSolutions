class Solution {
public:
    // T.C.=O(n^3), S.C.=O(1)
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long int maxVal = 0;

        for(int i=0; i<n-2; i++)
            for(int j=i+1; j<n-1; j++)
            {
                if(nums[i] <= nums[j])
                    continue;

                for(int k=j+1; k<n; k++)
                    maxVal = max(maxVal, (long long int)(nums[i] - nums[j]) * nums[k]);
            }

        return maxVal;
    }
};