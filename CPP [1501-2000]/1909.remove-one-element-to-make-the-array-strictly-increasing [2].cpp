class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) { // T.C.=O(n), S.C.=O(1)
        int n = nums.size();
        // count irregularities in forward direction
        int c1=0;
        int maxi = nums[0];
        for(int i=1; i<n; i++)
        {
            if(nums[i] <= maxi)
                c1++;
            maxi = max(maxi, nums[i]);
        }
        // count irregularities in backward direction
        int c2 = 0;
        int mini = nums[n-1];
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] >= mini)
                c2++;
            mini = min(mini, nums[i]);
        }
        return (c1 <= 1 || c2 <= 1) ? true : false;
    }
};