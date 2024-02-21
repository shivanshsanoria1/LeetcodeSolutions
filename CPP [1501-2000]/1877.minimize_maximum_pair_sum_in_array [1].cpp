class Solution {
public:
    int minPairSum(vector<int>& nums) { // T.C.=O(n*logn), S.C.=O(1)
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int ans = INT_MIN;
        for(int i=0; i<n/2; i++)
            ans = max(ans, nums[i] + nums[n-1-i]);
        return ans;
    }
};