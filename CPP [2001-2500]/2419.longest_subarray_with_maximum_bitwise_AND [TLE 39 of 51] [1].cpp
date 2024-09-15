class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxBitAND = 0;
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            int bitAND = INT_MAX;
            
            for(int j=i; j<n; j++)
            {
                bitAND &= nums[j];

                if(bitAND > maxBitAND)
                {
                    maxBitAND = bitAND;
                    ans = j-i+1;
                }
                else if(bitAND == maxBitAND)
                    ans = max(ans, j-i+1);
            }
        }

        return ans;
    }
};