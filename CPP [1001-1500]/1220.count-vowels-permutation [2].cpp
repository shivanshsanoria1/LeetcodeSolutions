class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    int countVowelPermutation(int n) { // Tabulation, T.C.=O(5*n), S.C.=O(1)
        if(n == 1)
            return 5;
        vector<unsigned int> prevDP(5, 1);
        vector<unsigned int> currDP(5);
        for(int i=2; i<=n; i++)
        {
            currDP[0] = (prevDP[1] + prevDP[2] + prevDP[4]) % MOD; // e,i,u 
            currDP[1] = (prevDP[0] + prevDP[2]) % MOD; // a,i
            currDP[2] = (prevDP[1] + prevDP[3]) % MOD; // e,o
            currDP[3] = prevDP[2]; // i
            currDP[4] = (prevDP[2] + prevDP[3]) % MOD; // i,o

            for(int j=0; j<5; j++) // update prevDP[]
                prevDP[j] = currDP[j];
        }
        int ans = 0;
        for(int j=0; j<5; j++) // nth row
            ans = (ans + currDP[j]) % MOD;
        return ans;
    }
};
// 0: 'a', 1: 'e', 2: 'i', 3: 'o', 4: 'u'
// dp[i][j]: num of strings of length i ending with the jth vowel