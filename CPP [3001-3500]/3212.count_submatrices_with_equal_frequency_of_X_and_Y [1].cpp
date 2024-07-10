class Solution {
private:
    typedef pair<int, int> PII;

public:
    // T.C.=O(m*n), S.C.=O(m*n)
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        // dp of size m*n filled with pairs {0, 0}
        vector<vector<PII>> dp(m, vector<PII>(n, {0, 0}));
        int count = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                auto [north_x, north_y] = i-1 >= 0 ? dp[i-1][j] : make_pair(0, 0);
                auto [west_x, west_y] = j-1 >= 0 ? dp[i][j-1] : make_pair(0, 0);
                auto [northWest_x, northWest_y] = i-1 >= 0 && j-1 >= 0 ? dp[i-1][j-1] : make_pair(0, 0);

                int curr_x = north_x + west_x - northWest_x + (grid[i][j] == 'X');
                int curr_y = north_y + west_y - northWest_y + (grid[i][j] == 'Y');

                dp[i][j] = {curr_x, curr_y};

                if(curr_x > 0 && curr_x == curr_y)
                    count++;
            }
        
        return count;
    }
};
// dp[i][j]: num of X's and Y's in the submatrix 
// with top-left corner at (0, 0) and 
// bottom-right corner at (i, j) in grid[][]