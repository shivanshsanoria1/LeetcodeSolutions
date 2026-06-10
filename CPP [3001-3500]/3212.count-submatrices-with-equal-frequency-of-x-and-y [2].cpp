class Solution {
private:
    typedef pair<int, int> PII;

public:
    // T.C.=O(m*n), S.C.=O((m+1)*(n+1))
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        // dp of size (m+1)*(n+1) filled with pairs {0, 0}
        vector<vector<PII>> dp(m+1, vector<PII>(n+1, {0, 0}));
        int count = 0;

        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
            {
                auto [north_x, north_y] = dp[i-1][j];
                auto [west_x, west_y] = dp[i][j-1];
                auto [northWest_x, northWest_y] = dp[i-1][j-1];

                int curr_x = north_x + west_x - northWest_x + (grid[i-1][j-1] == 'X');
                int curr_y = north_y + west_y - northWest_y + (grid[i-1][j-1] == 'Y');

                dp[i][j] = {curr_x, curr_y};

                if(curr_x > 0 && curr_x == curr_y)
                    count++;
            }
        
        return count;
    }
};
/*
# grid[i][j] is mapped with dp[i+1][j+1]
  or
  dp[i][j] is mapped with grid[i-1][j-1] 

# dp[i][j]: num of X's and Y's in the submatrix 
  with top-left corner at (0, 0) and 
  bottom-right corner at (i-1, j-1) in grid[][]
*/