class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int minLen = n+1;

        for(int i=0; i<n; i++)
        {
            int sum = 0;

            for(int j=i; j<n && j-i+1 < minLen; j++)
            {
                sum += nums[j];

                if(sum >= k)
                {
                    minLen = min(minLen, j-i+1);
                    break;
                }
            }
        }

        return minLen == n+1 ? -1 : minLen;
    }
};