class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    int countVowelPermutation(int n) { // Tabulation, T.C.=O(5*n), S.C.=O(5*n)
        // dp if size (n+1)*5 filled with 0's
        vector<vector<unsigned int>> dp(n+1, vector<unsigned int>(5, 0)); 
        for(int j=0; j<5; j++) // 1st row
            dp[1][j] = 1;
        for(int i=2; i<=n; i++)
        {
            dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4]) % MOD; // e,i,u 
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD; // a,i
            dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % MOD; // e,o
            dp[i][3] = dp[i-1][2]; // i
            dp[i][4] = (dp[i-1][2] + dp[i-1][3]) % MOD; // i,o
        }
        int ans = 0;
        for(int j=0; j<5; j++) // nth row
            ans = (ans + dp[n][j]) % MOD;
        return ans;
    }
};
// 0: 'a', 1: 'e', 2: 'i', 3: 'o', 4: 'u'
// dp[i][j]: num of strings of length i ending with jth vowel