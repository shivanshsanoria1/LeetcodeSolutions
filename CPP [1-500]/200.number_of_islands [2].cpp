class Solution {
public:
    typedef pair<int ,int> PI;
    
    void bfs(vector<vector<char>>& grid, vector<PI>& dirs, int x, int y){
        int row=grid.size(), col=grid[0].size();
        queue<pair<int,int>> q;
        grid[x][y] = '2'; // mark curr element as visited
        q.push({x, y}); // push curr index in queue
        while(!q.empty())
        {
            x = q.front().first; // x index of front element in queue
            y = q.front().second; // y index of front element in queue
            q.pop();
            for(auto dir: dirs) // move in 4 directions
            {
                int x1 = x + dir.first;
                int y1 = y + dir.second;
                if(x1<0 || x1>=row || y1<0 || y1>=col) // index out of bounds
                    continue;
                if(grid[x1][y1] == '1') // unvisited land 
                {
                    grid[x1][y1] = '2'; // mark the correct index element as visited
                    q.push({x1, y1}); // push the correct index in queuue
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size(), col=grid[0].size();
        int islands = 0;
        vector<PI> dirs = {{-1,0},{1,0},{0,-1},{0,1}}; // up, down, left, right
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(grid[i][j] == '1') // curr element is land
                {
                    bfs(grid, dirs, i, j);
                    islands++;
                }
        // [not required]: restore the original grid
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(grid[i][j] == '2')
                    grid[i][j] = '1';
        return islands;
    }
};
// 0: water, 1: unvisited land, 2: visited land