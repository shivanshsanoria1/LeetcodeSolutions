class Solution {
public:
    int solve(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j){
        int m=triangle.size();
        if(i < 0 || i >= m) // row index out of bounds
            return INT_MAX;
        int n=triangle[i].size();
        if(j < 0 || j >= n) // col index out of bounds
            return INT_MAX;
        if(i == m-1) // last row
            return triangle[i][j];
        if(dp[i][j] != -1) // solution exists in dp
            return dp[i][j];
        int down = solve(triangle, dp, i+1, j);
        int right = solve(triangle, dp, i+1, j+1);
        dp[i][j] = triangle[i][j] + min(down, right); // store the solution in dp
        return dp[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) { // Memoization
        int m=triangle.size();
        vector<vector<int>> dp;
        // dp of same size and structure as the input array (except the last row) filled with -1's
        for(int i=0; i<m-1; i++)
        {
            vector<int> temp(i+1, -1);
            dp.push_back(temp);
        }
        return solve(triangle, dp, 0, 0);
    }
};