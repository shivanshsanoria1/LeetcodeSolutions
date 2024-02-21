class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) { // T.C.=O(n), S.C.=O(1)
        int n=nums.size();
        int leftSum = 0;
        int rightSum = accumulate(nums.begin() + 1, nums.end(), 0);
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            ans[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
            rightSum -= i+1 < n ? nums[i+1] : 0;
        }
        return ans;
    }
};