#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class TraversalVisualiser{
private:
    static void logMsg(const string msg, const int separatorLen = 50){
        if(msg.length() > 0)
            cout<<msg<<endl;
        
        if(separatorLen > 0)
            cout<<endl<<string(separatorLen, '-')<<endl<<endl;
    }

    static string getColor(int num){
        switch(num){
            case 1: return "\033[32m"; // green
            case -1: return "\033[31m"; // red
            case 2: return "\033[33m"; // yellow
            case -2: return "\033[34m"; // blue
            default: return "\033[0m"; // white
        }
    }

    static void printGrid(const vector<vector<int>>& grid, vector<vector<int>>& colorGrid) {
        const int m = grid.size(), n = grid[0].size();
    
        // num of digits in the max number in grid
        int digs = 0;
    
        if(m*n <= 10)
            digs = 1;
        else if(m*n <= 100)
            digs = 2;
        else if(m*n <= 1000)
            digs = 3;
    
        string line = ".";
        for(int j=0; j<n; j++)
            line += " " + string(digs, '-') + " ."; 

        cout<<line<<endl;
        
        for(int i=0; i<m; i++){
            cout<<"| ";
    
            for(int j=0; j<n; j++){
                string str = to_string(grid[i][j]);

                str = string(digs - str.length(), ' ') + str;
                
                cout<<getColor(colorGrid[i][j]); // colored num
                cout<<str;
                cout<<getColor(0); // reset color
                cout<<" | ";
            }
    
            string line = ".";
            for(int j=0; j<n; j++)
                line += " " + string(digs, '-') + " .";

            cout<<endl<<line<<endl;
        }
        
        logMsg("");
    }
    
    // fill the grid with -1's
    static void resetGrid(vector<vector<int>>& grid){
        const int m = grid.size(), n = grid[0].size();
    
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                grid[i][j] = -1;
    }
    
    // starts DFS with curr value 'val' at coordinates {i, j}
    static void dfs(vector<vector<int>>& grid, int& val, int i, int j, vector<vector<int>>& colorGrid){
        const int m = grid.size(), n = grid[0].size();
        
        // index out of bounds
        if(i < 0 || i >= m || j < 0 || j >= n)
            return;
        
        // already visited
        if(grid[i][j] >= 0)
            return;
    
        grid[i][j] = val;

        colorGrid[i][j] = val % 2 == 0 ? 1 : -1;
        if(val == 0) // start-point
            colorGrid[i][j] = 2;
        else if(val == m*n - 1) // end-point
            colorGrid[i][j] = -2;

        val++;
    
        dfs(grid, val, i-1, j, colorGrid); // up
        dfs(grid, val, i, j+1, colorGrid); // right
        dfs(grid, val, i+1, j, colorGrid); // down
        dfs(grid, val, i, j-1, colorGrid); // left
    }

    static void updateFinalLayerColorBFS(vector<vector<int>>& grid, vector<vector<int>>& colorGrid){
        const int m = grid.size(), n = grid[0].size();
        int maxVal = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                maxVal = max(maxVal, grid[i][j]);

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == maxVal)
                    colorGrid[i][j] = -2; // final layer color
    }
    
    // starts BFS with initial value 'val' at coordinates {startX, startY}
    static void bfs(vector<vector<int>>& grid, int val, int startX, int startY, vector<vector<int>>& colorGrid){
        const int m = grid.size(), n = grid[0].size();
    
        // up, right, down, left
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
        queue<pair<int, int>> q;
        grid[startX][startY] = val;
        colorGrid[startX][startY] = 2; // start-point
        q.push({startX, startY});
        
        int parity = 1;
        while(!q.empty()){
            int sz = q.size();
            val++;
            
            while(sz--){
                const auto [currX, currY] = q.front();
                q.pop();
    
                for(const auto [dx, dy]: dirs){
                    const int x = currX + dx;
                    const int y = currY + dy;
                    
                    // index out of bounds
                    if(x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    
                    // already visited
                    if(grid[x][y] >= 0)
                        continue;
    
                    grid[x][y] = val;
                    colorGrid[x][y] = parity;
                    q.push({x, y});
                }
            }

            parity *= -1; // alternating color in each layer
        }

        updateFinalLayerColorBFS(grid, colorGrid);
    }

    static bool validateMode(string& mode){
        if(mode.length() != 3){
            logMsg("Mode length must be 3. Current mode length = " + to_string(mode.length()));
            return false;
        }
        
        const string modeInput = mode;
        transform(mode.begin(), mode.end(), mode.begin(), ::toupper);
        
        if(!(mode == "DFS" || mode == "BFS")){
            logMsg("Invalid mode: " + modeInput + ".\nAllowed modes are: 1. DFS, 2. BFS (case insensitive)");
            return false;
        }
    
        return true;
    }
    
    static bool validateGridDimensions(const int m, const int n){
        if(m < 1 || m > 100 || n < 1 || n > 100){
            logMsg("Dimensions of grid must be in range [1, 100]");
            return false;
        }
    
        if(m*n > 1000){
            logMsg("Maximum number of elements in grid must not exceed 1000");
            return false;
        }

        return true;
    }
    
    static bool validateGridCoordinates(const int m, const int n, const int i, const int j){
        if(!validateGridDimensions(m, n)){
            logMsg("Dimensions of grid must be in range [1, 100]");
            return false;
        }
        
        if(i < 0 || i >= m || j < 0 || j >= n){
            logMsg("Coordinates of point must be in range ([0, " + to_string(m) + "], [0, " + to_string(n) + "])");
            return false;
        }

        return true;
    }
    
public:
    TraversalVisualiser(){}
    
    // start DFS or BFS at a random point in grid of size m*n 
    static bool visualize(const int m, const int n, string mode){
        if(!validateMode(mode) || !validateGridDimensions(m, n))
            return false;
        
        srand(time(0)); // seed for rand()
        
        int i = rand() % m;
        int j = rand() % n;
        
        visualize(m, n, mode, i, j);
        
        return true;
    }
    
    // start DFS or BFS at a (i, j)) in grid of size m*n 
    static bool visualize(const int m, const int n, string mode, const int i, const int j){
        if(!validateMode(mode) || !validateGridDimensions(m, n) || !validateGridCoordinates(m, n, i, j))
            return false;
        
        vector<vector<int>> grid(m, vector<int>(n, -1));
        vector<vector<int>> colorGrid(m, vector<int>(n, 0));
        
        logMsg(mode + " started at (" + to_string(i) + ", " + to_string(j) + ") in a " + to_string(m) + " x " + to_string(n) + " grid", 0);
        
        int startVal = 0;
        
        if(mode == "DFS")
            dfs(grid, startVal, i, j, colorGrid);
        else if(mode == "BFS")
            bfs(grid, startVal, i, j, colorGrid);

        printGrid(grid, colorGrid);
        resetGrid(grid);
        
        return true;
    }
};

int main(){
    // start at random point
    TraversalVisualiser::visualize(10, 10, "dfs");
    
    // start at given point
    TraversalVisualiser::visualize(11, 11, "bfs", 5, 5);

    return 0;
}

/*
g++ "./misc/cpp/Visualizer for DFS and BFS.cpp" -o "./misc/cpp/compiled/Visualizer for DFS and BFS"
"./misc/cpp/compiled/Visualizer for DFS and BFS"
*/