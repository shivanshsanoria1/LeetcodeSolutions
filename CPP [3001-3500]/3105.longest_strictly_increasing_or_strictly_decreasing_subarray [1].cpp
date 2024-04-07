class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        
        // max length of strictly-increasing subarray
        int maxLenInc = 1;

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
            {
                if(nums[j-1] >= nums[j])
                    break;
                maxLenInc = max(maxLenInc, j-i+1);
            }
        
        // max length of strictly-decreasing subarray
        int maxLenDec = 1;

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
            {
                if(nums[j-1] <= nums[j])
                    break;
                maxLenDec = max(maxLenDec, j-i+1);
            }

        return max(maxLenInc, maxLenDec);
    }
};