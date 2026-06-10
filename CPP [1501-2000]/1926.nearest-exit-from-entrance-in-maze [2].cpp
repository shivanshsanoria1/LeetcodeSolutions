class Solution {
public:
    void recoverMaze(vector<vector<char>>& maze) //recovers the original maze
    {
        int m=maze.size(), n=maze[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(maze[i][j]=='V')
                    maze[i][j]='.';
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) { //T.C.=O(m*n) , S.C.=O(m*n) , BFS
        int m=maze.size(), n=maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]}); //push the coordinates of the entrance cell
        maze[entrance[0]][entrance[1]]='V'; //mark the entrance cell as visited
        int steps=-1; //keeps track of num of steps taken to reach the nearest exit cell
        while(!q.empty())
        {
            int size= q.size();
            steps++;
            while(size--)
            {
                int x= q.front().first;
                int y= q.front().second;
                q.pop();
                if(steps>0 && (x==0 || x==m-1 || y==0 || y==n-1)) //exit cell should be different from entrance cell
                {
                    recoverMaze(maze); //recover the original maze
                    return steps; //and at the edge of the maze
                }
                if(x-1>=0 && maze[x-1][y]!='+' && maze[x-1][y]!='V') //up
                {
                    q.push({x-1,y});
                    maze[x-1][y]='V';
                }
                if(x+1<m && maze[x+1][y]!='+' && maze[x+1][y]!='V') //down
                {
                    q.push({x+1,y});
                    maze[x+1][y]='V';
                }
                if(y-1>=0 && maze[x][y-1]!='+' && maze[x][y-1]!='V') //left
                {
                    q.push({x,y-1});
                    maze[x][y-1]='V';
                }
                if(y+1<n && maze[x][y+1]!='+' && maze[x][y+1]!='V') //right
                {
                    q.push({x,y+1});
                    maze[x][y+1]='V';
                }
            }
        }
        recoverMaze(maze); //recover the original maze
        return -1; //no path found
    }
};