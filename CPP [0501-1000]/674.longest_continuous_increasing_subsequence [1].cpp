class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) { // T.C.=O(n^2), S.C.=O(1)
        int n=nums.size();
        int ans = 1;
        for(int i=0; i<n-1; i++)
        {
            int subArrLen = 1;
            for(int j=i+1; j<n; j++)
            {
                if(nums[j-1] >= nums[j])
                    break;
                subArrLen++;
            }
            ans = max(ans, subArrLen);
        }
        return ans;
    }
};