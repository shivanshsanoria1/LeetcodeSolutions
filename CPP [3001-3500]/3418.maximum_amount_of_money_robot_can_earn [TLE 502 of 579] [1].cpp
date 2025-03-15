class Solution {
private:
    void solve(vector<vector<int>>& coins, int i, int j, int min1, int min2, int& sum, int& maxSum){
        int m = coins.size(), n = coins[0].size();
        
        if(i >= m || j >= n)
            return;

        sum += coins[i][j];

        if(coins[i][j] < 0)
        {
            if(coins[i][j] < min1)
            {
                min2 = min1;
                min1 = coins[i][j];
            }
            else if(coins[i][j] < min2)
                min2 = coins[i][j];
        }

        if(i == m-1 && j == n-1)
        {
            maxSum = max(maxSum, sum - min1 - min2);
            sum -= coins[i][j];
            return;
        }
        
        // down
        solve(coins, i+1, j, min1, min2, sum, maxSum);
        // right
        solve(coins, i, j+1, min1, min2, sum, maxSum);

        sum -= coins[i][j];
    }

public:
    // Recursion
    int maximumAmount(vector<vector<int>>& coins) {
        int sum = 0;
        int maxSum = INT_MIN;

        solve(coins, 0, 0, 0, 0, sum, maxSum);

        return maxSum;
    }
};