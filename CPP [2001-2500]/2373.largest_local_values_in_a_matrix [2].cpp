class Solution {
private:
    // returns max-val in the 9x9 grid centered at (i, j)
    int findMax(vector<vector<int>>& grid, int i, int j){
        // N, S, E, W, S-E, S-W, N-W, N-E
        vector<pair<int, int>> dirs = {{0,-1}, {0,1}, {-1,0}, {1,0}, {1,1}, {1,-1}, {-1,-1}, {-1, 1}};

        int maxVal = grid[i][j];

        for(auto [dx, dy]: dirs)
        {
            int x = i + dx;
            int y = j + dy;

            maxVal = max(maxVal, grid[x][y]); 
        }

        return maxVal;
    }

public:
    // T.C.=O(9*(n-2)^2), S.C.=O(9)
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<vector<int>> ans(n-2, vector<int>(n-2, 0));

        for(int i=1; i<n-1; i++)
            for(int j=1; j<n-1; j++)
                ans[i-1][j-1] = findMax(grid, i, j);

        return ans;
    }
};
/*
# N: North
# S: South
# E: East
# W: West
*/