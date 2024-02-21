class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) { // DP, T.C.=O(n1*n2), S.C.=O(n1*n2)
        int n1=nums1.size(), n2=nums2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0)); // dp of size (n1+1)*(n2+1) filled with 0's
        int ans = 0;
        for(int i=1; i<=n1; i++)
            for(int j=1; j<=n2; j++)
                if(nums1[i-1] == nums2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
        return ans;
    }
};
// dp[i][j]: length of LCS when nums1[] end at index i-1 and nums2[] end at index j-1 