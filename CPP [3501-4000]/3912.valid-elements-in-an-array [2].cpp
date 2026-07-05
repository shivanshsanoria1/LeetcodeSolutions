class Solution {
public:
    // T.C.=O(n), S.C.=O(2*n)
    vector<int> findValidElements(vector<int>& nums) {
        const int n = nums.size();

        vector<int> leftMax(n, nums[0]);
        for(int i=1; i<n; i++)
            leftMax[i] = max(leftMax[i-1], nums[i]);

        vector<int> rightMax(n, nums[n-1]);
        for(int i=n-2; i>=0; i--)
            rightMax[i] = max(rightMax[i+1], nums[i]);

        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1; i<n-1; i++)
            if(nums[i] > leftMax[i-1] || nums[i] > rightMax[i+1])
                ans.push_back(nums[i]);

        if(n > 1)
            ans.push_back(nums[n-1]);

        return ans;
    }
};