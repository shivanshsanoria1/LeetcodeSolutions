class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) { // DP
        int m=triangle.size();
        vector<vector<int>> dp;
        // dp of same size and structure as the input array filled with -1's
        for(int i=0; i<m; i++)
        {
            vector<int> temp(i+1, -1);
            dp.push_back(temp);
        }
        for(int j=0; j<triangle[m-1].size(); j++) // last row 
            dp[m-1][j] = triangle[m-1][j];
        for(int i=m-2; i>=0; i--)
        {
            int n=triangle[i].size();
            for(int j=0; j<n; j++)
            {
                int down = dp[i+1][j];
                int right = j < n ? dp[i+1][j+1] : INT_MAX;
                dp[i][j] = triangle[i][j] + min(down, right);
            }
        }
        return dp[0][0];
    }
};