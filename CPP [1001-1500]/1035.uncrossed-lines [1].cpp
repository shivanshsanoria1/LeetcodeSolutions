class Solution {
public:
    int lcs(vector<vector<int>>& dp, vector<int>& nums1, vector<int>& nums2, int i, int j){
        if(i == nums1.size() || j == nums2.size()) // index out of bounds
            return 0;
        if(dp[i][j] != -1) // solution already exists in dp
            return dp[i][j];
        if(nums1[i] == nums2[j]) // ith element of num1 matches with jth element of nums2
        {
            // move 1 step forward in nums1 and nums2
            dp[i][j] = 1 + lcs(dp, nums1, nums2, i+1, j+1);
            return dp[i][j];
        }
        int a = lcs(dp, nums1, nums2, i+1, j); // move 1 step forward in nums1
        int b = lcs(dp, nums1, nums2, i, j+1); // move 1 step forward in nums2
        dp[i][j] = max(a, b);
        return dp[i][j];
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) { // Memoization, T.C.=O(n1*n2), S.C.=O(n1*n2)
        int n1=nums1.size(), n2=nums2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1)); // dp of size n1*n2 filled with -1's
        return lcs(dp, nums1, nums2, 0, 0);
    }
};
// same as Leetcode-1143 : longest common subsequence