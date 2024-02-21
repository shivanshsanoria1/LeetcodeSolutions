class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n), Tabulation
    int lengthOfLIS(vector<int>& nums) { 
        int n=nums.size();
        // stores the length of LIS starting from ith index
        vector<int> lis(n, 1); 
        int ans = lis[n-1];
        for(int i=n-2; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
                if(nums[i] < nums[j])
                    lis[i] = max(lis[i], 1 + lis[j]);
            ans = max(ans, lis[i]);
        }
        return ans;
    }
};