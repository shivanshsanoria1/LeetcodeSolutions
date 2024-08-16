class DetectSquares {
private:
    // grid[i][j]: freq of the point {x, y}
    vector<vector<int>> grid;

    bool isValidPoint(int x, int y){
        return x >= 0 && x <= 1000 && y >= 0 && y <= 1000;
    }

public:
    DetectSquares() {
        this->grid.resize(1001, vector<int>(1001, 0));
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        grid[x][y]++;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        for(int k=1; k<=1000; k++)
        {
            int x1 = x , y1 = y + k; // North 
            int x2 = x , y2 = y - k; // South
            int x3 = x + k, y3 = y; // East
            int x4 = x - k, y4 = y; // West
            int x5 = x + k, y5 = y + k; // North-East
            int x6 = x - k, y6 = y + k; // North-West
            int x7 = x + k, y7 = y - k; // South-East
            int x8 = x - k, y8 = y - k; // South-West
            
            // all diagonal indexes are out of bounds
            if(!isValidPoint(x5,y5) && !isValidPoint(x6,y6) && !isValidPoint(x7,y7) && !isValidPoint(x8,y8))
                break;
            
            // North, East, North-East exists
            if(isValidPoint(x1,y1) && isValidPoint(x3,y3) && isValidPoint(x5,y5))
                ans += grid[x1][y1] * grid[x3][y3] * grid[x5][y5];
            // North, West, North-West exists
            if(isValidPoint(x1,y1) && isValidPoint(x4,y4) && isValidPoint(x6,y6))
                ans += grid[x1][y1] * grid[x4][y4] * grid[x6][y6];
            // South, East, South-East exists
            if(isValidPoint(x2,y2) && isValidPoint(x3,y3) && isValidPoint(x7,y7))
                ans += grid[x2][y2] * grid[x3][y3] * grid[x7][y7];
            // South, West, South-West exists
            if(isValidPoint(x2,y2) && isValidPoint(x4,y4) && isValidPoint(x8,y8))
                ans += grid[x2][y2] * grid[x4][y4] * grid[x8][y8];
        }

        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

/*

(x6,y6) - (x1,y1) - (x5,y5)
   |         |         |
(x4,y4)    (x,y)    (x3,y3)
   |         |         |
(x8,y8) - (x2,y2) - (x7,y7)

*/