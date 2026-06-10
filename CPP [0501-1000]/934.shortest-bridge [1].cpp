class Solution {
public:
    bool isValidIndex(int n, int i, int j){
        return (i<0 || i>=n || j<0 || j>=n) ? false : true;
    }

    int bfs(vector<vector<int>>& grid, queue<pair<int, int>> &q)
    {
        int n = grid.size();
        int dist = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                pair<int, int> curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                // check the 4-directional elements have valid index and are unvisited
                // push only elements with value 0 in the queue
                // element with value 1 means 2nd island is found
                if(isValidIndex(n, i-1, j) && grid[i-1][j] <= 1) // up
                {
                    if(grid[i-1][j] == 1)
                        return dist;
                    grid[i-1][j] += 10;
                    q.push({i-1, j});
                }
                if(isValidIndex(n, i+1, j) && grid[i+1][j] <= 1) // down
                {
                    if(grid[i+1][j] == 1)
                        return dist;
                    grid[i+1][j] += 10;
                    q.push({i+1, j}); 
                }
                if(isValidIndex(n, i, j-1) && grid[i][j-1] <= 1) // left
                {
                    if(grid[i][j-1] == 1)
                        return dist;
                    grid[i][j-1] += 10;
                    q.push({i, j-1}); 
                }
                if(isValidIndex(n, i, j+1) && grid[i][j+1] <= 1) // right
                {
                    if(grid[i][j+1] == 1)
                        return dist;
                    grid[i][j+1] += 10;
                    q.push({i, j+1}); 
                }
            }
            dist++;
        }
        return dist;
    }

    void dfs(queue<pair<int, int>> &q, vector<vector<int>>& grid, int i, int j)
    {
        int n = grid.size();
        if(isValidIndex(n, i, j) == false) // index out of bounds
            return;
        if(grid[i][j] != 1) // curr element is not an unvisited land
            return;
        grid[i][j] += 10; // mark the curr land as visited
        q.push({i, j}); // push the curr corrdinates in queue
        dfs(q, grid, i-1, j); // up
        dfs(q, grid, i+1, j); // down
        dfs(q, grid, i, j-1); // left
        dfs(q, grid, i, j+1); // right
    }

    int shortestBridge(vector<vector<int>>& grid) { // T.C.=O(n^2)
        int n = grid.size();
        bool flag = false;
        queue<pair<int, int>> q; // to store the coordinates of the 1st island
        for(int i=0; i<n; i++) // find the first 1 in the grid
        {
            for(int j=0; j<n; j++)
                if(grid[i][j] == 1)
                {
                    dfs(q, grid, i, j); // find the 1st island
                    flag = true;
                    break;
                }
            if(flag == true)
                break;
        }
        
        int ans = bfs(grid, q);

        for(int i=0; i<n; i++) // [not required]: recover the original grid
            for(int j=0; j<n; j++)
                if(grid[i][j] >= 10)
                    grid[i][j] -= 10;

        return ans;
    }
};