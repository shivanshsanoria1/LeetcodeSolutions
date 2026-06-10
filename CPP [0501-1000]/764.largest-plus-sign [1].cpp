class Solution {
public:
    // T.C.=O(n^2), S.C.=O(5*n^2)
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        // n*n grid filled with 1's
        vector<vector<int>> grid(n, vector<int>(n, 1));
        // mark the 0's in the grid
        for(int i=0; i<mines.size(); i++)
            grid[mines[i][0]][mines[i][1]] = 0;

        vector<vector<int>> dp_up(n, vector<int>(n, 0));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 1)
                    dp_up[i][j] = i-1 >= 0 ? 1 + dp_up[i-1][j] : 1;
        
        vector<vector<int>> dp_down(n, vector<int>(n, 0));
        for(int i=n-1; i>=0; i--)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 1)
                    dp_down[i][j] = i+1 < n ? 1 + dp_down[i+1][j] : 1;

        vector<vector<int>> dp_left(n, vector<int>(n, 0));
        for(int j=0; j<n; j++)
            for(int i=0; i<n; i++)
                if(grid[i][j] == 1)
                    dp_left[i][j] = j-1 >= 0 ? 1 + dp_left[i][j-1] : 1;
        
        vector<vector<int>> dp_right(n, vector<int>(n, 0));
        for(int j=n-1; j>=0; j--)
            for(int i=0; i<n; i++)
                if(grid[i][j] == 1)
                    dp_right[i][j] = j+1 < n ? 1 + dp_right[i][j+1] : 1;

        int k = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                k = max(k, min(min(dp_up[i][j], dp_down[i][j]), min(dp_left[i][j], dp_right[i][j])));

        return k;
    }
};