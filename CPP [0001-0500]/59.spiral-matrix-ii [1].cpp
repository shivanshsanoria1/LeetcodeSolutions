class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    vector<vector<int>> generateMatrix(int n) {
        // n*n grid filled with 0's
        vector<vector<int>> grid(n, vector<int>(n, 0));
        // right, down, left, up
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // directional index
        int i = 0; 
        // curr coordinates
        int currX = 0, currY = 0;

        for(int val=1; val <= n*n; val++)
        {
            // fill the cell with curr coordinates
            grid[currX][currY] = val;
            
            // next possible coordinates
            int nextX = currX + dirs[i].first;
            int nextY = currY + dirs[i].second;
            
            // change the direction if the next coordinates reach out of bounds
            // or is already filled
            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= n || grid[nextX][nextY] > 0)
                i = (i + 1) % 4;

            // update the curr coordinates
            currX += dirs[i].first;
            currY += dirs[i].second;
        }

        return grid;
    }
};