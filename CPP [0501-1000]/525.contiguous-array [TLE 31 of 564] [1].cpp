class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int maxLen = 0;
        for(int i=0; i<n; i++)
        {
            int zeros = 0, ones = 0;
            for(int j=i; j<n; j++)
            {
                if(nums[j] == 0)
                    zeros++;
                else // nums[j] == 1
                    ones++;
                if(zeros == ones)
                    maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
};