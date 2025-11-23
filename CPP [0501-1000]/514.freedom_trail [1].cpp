class Solution {
private:
    int solve(string& ring, string& key, int i, int j, vector<vector<int>>& dp){
        // all chars in 'key' are found
        if(j >= key.length())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int n=ring.length();
        int minSteps = INT_MAX;

        for(int k=0; k<n; k++)
        {
            if(ring[k] != key[j])
                continue;

            // min distance between indexes k and i 
            // (in both forward and backward direction)
            int minDist = min((k-i+n) % n, (i-k+n) % n);
            
            minSteps = min(minSteps, minDist + solve(ring, key, k, j+1, dp));
        }
        
        // +1 is done since each char requires a button press
        // which is also counted as a step
        dp[i][j] = 1 + minSteps;

        return dp[i][j]; 
    }

public:
    // T.C.=O(n^2 * m), S.C.=O(n*m)
    // n: length of 'ring', m: length of 'key'
    // DP-Memoization
    int findRotateSteps(string ring, string key) {
        int n=ring.length(), m=key.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(ring, key, 0, 0, dp);
    }
};