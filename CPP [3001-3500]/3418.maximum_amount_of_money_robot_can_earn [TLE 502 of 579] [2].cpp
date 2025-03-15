class Solution {
private:
    #define INF -int(1e9)

    int solve(vector<vector<int>>& coins, int i, int j, int k){
        int m = coins.size(), n = coins[0].size();
        
        if(i >= m || j >= n)
            return INF;
        
        if(i == m-1 && j == n-1)
            return coins[i][j] < 0 && k > 0 ? 0 : coins[i][j];

        // result with neutralization
        int res1 = INF;

        if(coins[i][j] < 0 && k > 0)
        {
            int down = solve(coins, i+1, j, k-1);
            int right = solve(coins, i, j+1, k-1);

            res1 = max(down, right);
        }
        
        // result without neutralization
        int down = solve(coins, i+1, j, k);
        int right = solve(coins, i, j+1, k);

        int res2 = coins[i][j] + max(down, right);

        return max(res1, res2);
    }

public:
    // Recursion
    int maximumAmount(vector<vector<int>>& coins) {
        return solve(coins, 0, 0, 2);
    }
};