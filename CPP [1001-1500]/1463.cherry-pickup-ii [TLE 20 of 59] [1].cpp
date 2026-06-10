class Solution {
private:
    int solve(vector<vector<int>>& grid, int r, int c1, int c2){
        int m=grid.size(), n=grid[0].size();

        if(min(c1, c2) < 0 || max(c1, c2) >= n)
            return 0;
        if(r == m-1)
            return grid[r][c1] + grid[r][c2];

        vector<int> dirs = {-1, 0, 1};

        int res = 0;
        for(int dy1: dirs)
            for(int dy2: dirs)
            {
                int y1 = c1 + dy1;
                int y2 = c2 + dy2;
                if(y1 == y2)
                    continue;
                res = max(res, solve(grid, r+1, y1, y2));
            }
        
        return res + grid[r][c1] + grid[r][c2];
    }

public:
    // T.C.=O(9^m), S.C.=O(m), Recursion
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid[0].size();
        return solve(grid, 0, 0, n-1);
    }
};