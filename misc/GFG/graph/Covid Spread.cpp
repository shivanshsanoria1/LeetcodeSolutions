class Solution {
private:
    typedef pair<int, int> PI;

    int bfs(vector<vector<int>>& grid, queue<PI>& q){ // multi-source BFS
        int m=grid.size(), n=grid[0].size();
        // up, down, left, right
        vector<PI> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int level = -1;
        while(!q.empty())
        {
            int size = q.size();
            level++;
            while(size--)
            {
                int currX = q.front().first;
                int currY = q.front().second;
                q.pop();
                for(auto dir: dirs)
                {
                    int x = currX + dir.first;
                    int y = currY + dir.second;
                    // index out of bounds
                    if(x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    // skip anything but the uninfected patient
                    if(grid[x][y] != 1)
                        continue;
                    grid[x][y] *= -1;
                    q.push({x, y});
                }   
            }
        }
        return level;
    }

    bool resetGrid(vector<vector<int>>& grid){
        int m=grid.size(), n=grid[0].size();
        bool possible = true; // assume all patients finally get infected
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] < 0)
                    grid[i][j] *= -1;
                else if(grid[i][j] == 1) // uninfected patient found
                    possible = false;
            }
        return possible;
    }

public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int m=hospital.size(), n=hospital[0].size();
        queue<PI> q;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                // push all the initial infected patients in queue
                if(hospital[i][j] == 2) 
                {
                    hospital[i][j] *= -1;
                    q.push({i, j});
                }
        int ans = bfs(hospital, q);
        bool possible = resetGrid(hospital);
        return possible ? ans : -1;
    }
};