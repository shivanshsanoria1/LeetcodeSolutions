class Solution {
public:
    bool isValidIndex(int n, int i, int j){
        return (i<0 || i>=n || j<0 || j>=n) ? false : true;
    }

    int bfs(vector<vector<int>>& grid, set<pair<int, int>> &visited)
    {
        queue<pair<int, int>> q;
        for(auto it: visited) // push the coordinates of 1st island into the queue
            q.push({it.first, it.second});
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
                if(isValidIndex(n, i-1, j) && visited.find({i-1, j}) == visited.end()) // up
                {
                    if(grid[i-1][j] == 1)
                        return dist;
                    visited.insert({i-1, j});
                    q.push({i-1, j});
                }
                if(isValidIndex(n, i+1, j) && visited.find({i+1, j}) == visited.end()) // down
                {
                    if(grid[i+1][j] == 1)
                        return dist;
                    visited.insert({i+1, j});
                    q.push({i+1, j}); 
                }
                if(isValidIndex(n, i, j-1) && visited.find({i, j-1}) == visited.end()) // left
                {
                    if(grid[i][j-1] == 1)
                        return dist;
                    visited.insert({i, j-1});
                    q.push({i, j-1}); 
                }
                if(isValidIndex(n, i, j+1) && visited.find({i, j+1}) == visited.end()) // right
                {
                    if(grid[i][j+1] == 1)
                        return dist;
                    visited.insert({i, j+1});
                    q.push({i, j+1}); 
                }
            }
            dist++;
        }
        return dist;
    }

    void dfs(set<pair<int, int>> &visited, vector<vector<int>>& grid, int i, int j)
    {
        int n = grid.size();
        if(isValidIndex(n, i, j) == false) // index out of bounds
            return;
        if(grid[i][j] == 0) // curr element is water
            return;
        if(visited.find({i, j}) != visited.end()) // curr element is visited land
            return;
        visited.insert({i, j}); // mark the curr land as visited
        dfs(visited, grid, i-1, j); // up
        dfs(visited, grid, i+1, j); // down
        dfs(visited, grid, i, j-1); // left
        dfs(visited, grid, i, j+1); // right
    }

    int shortestBridge(vector<vector<int>>& grid) { // T.C.=O(n^2)
        int n = grid.size();
        bool flag = false;
        set<pair<int, int>> visited; // to store the coordinates of visited elements
        for(int i=0; i<n; i++) // find the first 1 in the grid
        {
            for(int j=0; j<n; j++)
                if(grid[i][j] == 1)
                {
                    dfs(visited, grid, i, j); // find the 1st island
                    flag = true;
                    break;
                }
            if(flag == true)
                break;
        }
        
        return bfs(grid, visited);
    }
};
// NOTE: unordered_set of pairs is not allowed so set is used