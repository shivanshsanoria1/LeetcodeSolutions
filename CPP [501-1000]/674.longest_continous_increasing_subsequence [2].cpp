class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) { // T.C.=O(n), S.C.=O(1)
        int ans = 1;
        int subArrLen = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i-1] < nums[i])
                subArrLen++;
            else
            {
                ans = max(ans, subArrLen);
                subArrLen = 1; // reset the max subarray length
            }
        }
        // max(ans, subArrLen) is used instead of ans, in case the entire array is strictly increasing
        return max(ans, subArrLen);
    }
};