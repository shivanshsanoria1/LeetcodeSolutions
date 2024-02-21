class Solution {
public:
    int alternatingSubarray(vector<int>& nums) { // T.C.=O(n^2), S.C.=O(1)
        int n=nums.size();
        int maxLen = 1;
        for(int i=0; i<n-1; i++)
        {
            int currLen = 1;
            int mul = 1;
            for(int j=i+1; j<n; j++)
            {
                if(nums[j] - nums[j-1] == mul)
                {
                    currLen++;
                    mul *= -1;
                }
                else
                    break;
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen == 1 ? -1 : maxLen;
    }
};