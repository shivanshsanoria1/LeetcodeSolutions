class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int minLen = INT_MAX;

        for(int i=0; i<n; i++)
        {
            int bitOR = 0; 

            for(int j=i; j<n; j++)
            {
                bitOR = bitOR | nums[j];

                if(bitOR >= k)
                    minLen = min(minLen, j-i+1);
            }
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};