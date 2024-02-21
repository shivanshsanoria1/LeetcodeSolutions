class Solution {
private:
    // (i,j): curr cell, (pi,pj): parent cell
    typedef pair<pair<int, int>, pair<int, int>> PP; // {{i, j}, {pi, pj}}

public:
    bool bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        int m=grid.size(), n=grid[0].size();
        // directions- up, down, left, right
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        queue<PP> q;
        visited[i][j] = true; // mark the start cell as visited
        q.push({{i, j}, {-1, -1}}); // start cell has no parent cell, so {-1,-1} is used as parent
        while(!q.empty())
        {
            auto [currX, currY] = q.front().first; // curr cell coordinates
            auto [parX, parY] = q.front().second; // parent cell of curr cell coordinates
            q.pop();
            for(auto [dx, dy]: dirs)
            {
                int x = currX + dx; // next cell x coordinate
                int y = currY + dy; // next cell y coordinate
                if(x < 0 || x >= m || y < 0 || y >= n) // index out of bounds
                    continue;
                if(grid[x][y] != grid[currX][currY]) // char mismatch between next and curr cell
                    continue;
                if(x == parX && y == parY) // next cell is the parent cell of curr cell
                    continue;
                if(visited[x][y]) // already visited cell which is not the parent cell, ie, loop found
                    return true;
                visited[x][y] = true; // mark the next cell as visited
                // push the nex cell coordinates in queue, curr cell as parent cell
                q.push({{x, y}, {currX, currY}}); 
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) { // T.C.=O(m*n), S.C.=O(m*n)
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> visited(m, vector(n, false));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                // run bfs() only for unvisited cells
                if(!visited[i][j] && bfs(grid, visited, i, j))
                    return true;
        return false;
    }
};