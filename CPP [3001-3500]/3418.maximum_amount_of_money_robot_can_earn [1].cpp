class Solution {
private:
    #define INF -int(1e9)

    typedef vector<int> VEC1D;
    typedef vector<vector<int>> VEC2D;
    typedef vector<vector<vector<int>>> VEC3D;

    int solve(vector<vector<int>>& coins, int i, int j, int k, VEC3D& dp){
        int m = coins.size(), n = coins[0].size();
        
        if(i >= m || j >= n)
            return INF;
        
        if(dp[i][j][k] != INF)
            return dp[i][j][k];
        
        if(i == m-1 && j == n-1)
        {
            dp[i][j][k] = coins[i][j] < 0 && k > 0 ? 0 : coins[i][j];
            return dp[i][j][k]; 
        }

        // result with neutralization
        int res1 = INF;
        if(coins[i][j] < 0 && k > 0)
        {
            int down = solve(coins, i+1, j, k-1, dp);
            int right = solve(coins, i, j+1, k-1, dp);
            
            res1 = max(down, right);
        }
        
        // result without neutralization
        int down = solve(coins, i+1, j, k, dp);
        int right = solve(coins, i, j+1, k, dp);

        int res2 = coins[i][j] + max(down, right);

        dp[i][j][k] = max(res1, res2);
        return dp[i][j][k]; 
    }

public:
    // T.C.=O(m*n*3), S.C.=O(m*n*3)
    // DP: Memoization
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        VEC3D dp(m, VEC2D(n, VEC1D(3, INF)));

        return solve(coins, 0, 0, 2, dp);
    }
};