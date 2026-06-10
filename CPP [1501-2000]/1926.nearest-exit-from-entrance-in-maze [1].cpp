class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) { //T.C.=O(m*n) , S.C.=O(m*n) , BFS
        int m=maze.size(), n=maze[0].size();
        vector<vector<bool>> visited(m,vector(n,false)); //keeps track of visited cells
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]}); //push the coordinates of the entrance cell
        visited[entrance[0]][entrance[1]]=true; //mark the entrance cell as visited
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
                    return steps; //and at the edge of the maze
                if(x-1>=0 && maze[x-1][y]!='+' && visited[x-1][y]==false) //up
                {
                    q.push({x-1,y});
                    visited[x-1][y]=true;
                }
                if(x+1<m && maze[x+1][y]!='+' && visited[x+1][y]==false) //down
                {
                    q.push({x+1,y});
                    visited[x+1][y]=true;
                }
                if(y-1>=0 && maze[x][y-1]!='+' && visited[x][y-1]==false) //left
                {
                    q.push({x,y-1});
                    visited[x][y-1]=true;
                }
                if(y+1<n && maze[x][y+1]!='+' && visited[x][y+1]==false) //right
                {
                    q.push({x,y+1});
                    visited[x][y+1]=true;
                }
            }
        }
        return -1; //no path found
    }
};