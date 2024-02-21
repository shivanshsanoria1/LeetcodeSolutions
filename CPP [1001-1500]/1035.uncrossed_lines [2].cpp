class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) { // DP, T.C.=O(n1*n2), S.C.=O(n1*n2)
        int n1=nums1.size(), n2=nums2.size();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1)); // dp of size (n1+1)*(n2+1) filled with -1's
        for(int i=0; i<=n1; i++) // fill the 0th col with 0's
            dp[i][0] = 0;
        for(int j=0; j<=n2; j++) // fill the 0th row with 0's
            dp[0][j] = 0;
        for(int i=1; i<=n1; i++)
            for(int j=1; j<=n2; j++)
            {
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        return dp[n1][n2]; // return the last element in dp
    }
};
// same as Leetcode-1143 : longest common subsequence
// ith index of dp is mapped with (i-1)th index of s1
// jth index of dp is mapped with (j-1)th index of s2