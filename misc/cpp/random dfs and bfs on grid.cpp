#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstdlib>
#include <time.h>

using namespace std;

void printGrid(vector<vector<int>>& grid) {
    int m=grid.size(), n=grid[0].size();

    // num of digits in max number in grid
    int digs = 0;

    if(m*n <= 10)
        digs = 1;
    else if(m*n <= 100)
        digs = 2;
    else if(m*n <= 1000)
        digs = 3;

    string line = ".";
    for(int j=0; j<n; j++){
        if(digs == 1)
            line += " - .";
        else if(digs == 2)
            line += " -- .";
        else if(digs == 3)
            line += " --- .";
    }
    cout<<line<<endl;

    for(int i=0; i<m; i++){
        cout<<"| ";

        for(int j=0; j<n; j++){
            string str = to_string(grid[i][j]);

            if(digs - str.length() == 1)
                str = "0" + str;
            else if(digs - str.length() == 2)
                str = "00" + str;

            cout<<str<<" | ";
        }

        string line = ".";
        for(int j=0; j<n; j++){
            if(digs == 1)
                line += " - .";
            else if(digs == 2)
                line += " -- .";
            else if(digs == 3)
                line += " --- .";
        }
        cout<<endl<<line<<endl;
    }

    cout<<endl<<"------------------------------"<<endl<<endl;
}

// fill the grid with -1's
void resetGrid(vector<vector<int>>& grid){
    int m=grid.size(), n=grid[0].size();

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            grid[i][j] = -1;
}

// starts DFS with curr value 'val' at coordinates {i, j}
void dfs(vector<vector<int>>& grid, int& val, int i, int j){
    int m=grid.size(), n=grid[0].size();

    if(i<0 || i>=m || j<0 || j>=n)
        return;

    if(grid[i][j] >= 0)
        return;

    grid[i][j] = val;
    val++;

    dfs(grid, val, i-1, j); // up
    dfs(grid, val, i, j+1); // right
    dfs(grid, val, i+1, j); // down
    dfs(grid, val, i, j-1); // left
}

// starts BFS with initial value 'val' at coordinates {startX, startY}
void bfs(vector<vector<int>>& grid, int val, int startX, int startY){
    int m=grid.size(), n=grid[0].size();

    // up-right-down-left
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    queue<pair<int, int>> q;
    grid[startX][startY] = val;
    q.push({startX, startY});

    while(!q.empty()){
        int size = q.size();
        val++;

        while(size--){
            auto [currX, currY] = q.front();
            q.pop();

            for(auto [dx, dy]: dirs){
                int x = currX + dx;
                int y = currY + dy;

                if(x<0 || x>=m || y<0 || y>=n)
                    continue;

                if(grid[x][y] >= 0)
                    continue;

                grid[x][y] = val;

                q.push({x, y});
            }
        }
    }
}

// start DFS (mode == 'd') or BFS (mode == 'b') at a random point
// in grid of size m*n for 'iterations' number of iterations
void randomStart(int m, int n, char mode, int iterations){
    if(!(mode != 'b' || mode != 'd')){
        cout<<"Error: Invalid mode"<<endl;
        return;
    }

    if(m<1 || m>100 || n<1 || n>100){
        cout<<"Error: dimensions of grid must be in range [1, 100]"<<endl;
        return;
    }

    if(m*n > 1000){
        cout<<"Error: maximum number of elements in grid must not exceed 1000"<<endl;
        return;
    }

    vector<vector<int>> grid(m, vector<int>(n, -1));

    string modeStr = mode == 'b' ? "BFS" : "DFS";

    cout<<"Generating "<<iterations<<" grids in "<<modeStr<<" mode with random starting coordinates..."<<endl<<endl;

    srand(time(0));

    for(int i=1; i<=iterations; i++){
        int startVal = 0;
        int startX = rand() % m;
        int startY = rand() % n;

        cout<<i<<". "<<modeStr<<" started at ("<<startX<<", "<<startY<<")"<<endl<<endl;

        if(mode == 'd')
            dfs(grid, startVal, startX, startY);
        else if(mode == 'b')
            bfs(grid, startVal, startX, startY);

        printGrid(grid);
        resetGrid(grid);
    }
}

int main()
{

    //randomStart(10, 10, 'd', 1);
    randomStart(12, 12, 'b', 1);

    return 0;
}
