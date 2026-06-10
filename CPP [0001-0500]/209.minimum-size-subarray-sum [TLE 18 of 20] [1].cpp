class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) { // T.C.=O(n^2), S.C.=O(1)
        int n=nums.size();
        int minLen = INT_MAX; // min length of valid subarray (subarray whose sum >= target)
        for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i; j<n; j++)
            {
                sum += nums[j];
                if(sum >= target)
                {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};