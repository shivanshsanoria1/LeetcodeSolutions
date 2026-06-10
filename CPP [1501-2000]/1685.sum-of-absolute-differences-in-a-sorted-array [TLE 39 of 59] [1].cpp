class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) { // T.C.=O(n^2), S.C.=O(1)
        int n=nums.size();
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                ans[i] += abs(nums[i] - nums[j]);
        return ans;
    }
};