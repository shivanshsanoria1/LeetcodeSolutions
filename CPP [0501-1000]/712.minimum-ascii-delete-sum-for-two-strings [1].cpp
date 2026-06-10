class Solution {
private:
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp, vector<int>& postfixSum1, vector<int>& postfixSum2){
        int n1=s1.length(), n2=s2.length();

        // both s1 and s2 are exhausted, so 
        // no more operations are needed
        if(i == n1 && j == n2)
            return 0;
        
        // s1 is exhausted; so delete the
        // remaining (n2 - j) chars from s2
        if(i == n1)
            return postfixSum2[j];
        
        // s2 is exhausted; so delete the
        // remaining (n1 - i) chars from s1
        if(j == n2)
            return postfixSum1[i];

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j])
        {
            dp[i][j] = solve(s1, s2, i+1, j+1, dp, postfixSum1, postfixSum2);
            return dp[i][j];
        }
        
        int deleteFromS1 = int(s1[i]) + solve(s1, s2, i+1, j, dp, postfixSum1, postfixSum2);
        int deleteFromS2 = int(s2[j]) + solve(s1, s2, i, j+1, dp, postfixSum1, postfixSum2);

        dp[i][j] = min(deleteFromS1, deleteFromS2);
        return dp[i][j]; 
    }

public:
    // T.C.=O(n1*n2), S.C.=O(n1*n2)
    // DP: Memoization
    int minimumDeleteSum(string s1, string s2) {
        int n1=s1.length(), n2=s2.length();
        
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        
        vector<int> postfixSum1(n1, 0);
        vector<int> postfixSum2(n2, 0);

        postfixSum1[n1 - 1] = int(s1[n1 - 1]);
        for(int i=n1-2; i>=0; i--)
            postfixSum1[i] = int(s1[i]) + postfixSum1[i+1];
        
        postfixSum2[n2 - 1] = int(s2[n2 - 1]);
        for(int i=n2-2; i>=0; i--)
            postfixSum2[i] = int(s2[i]) + postfixSum2[i+1];


        return solve(s1, s2, 0, 0, dp, postfixSum1, postfixSum2);
    }
};

// similar: [72. edit-distance]