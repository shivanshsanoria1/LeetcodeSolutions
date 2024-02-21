class DetectSquares {
private:
    vector<vector<int>> grid;

public:
    DetectSquares() {
        grid.resize(1001, vector<int>(1001, 0));
    }
    
    void add(vector<int> point) {
        grid[point[0]][point[1]]++;
    }
    
    bool isValidIndex(int i, int j){
        return i < 0 || i > 1000 || j < 0 || j > 1000 ? false : true;
    }

    int count(vector<int> point) {
        int ans = 0;
        int x = point[0];
        int y = point[1];
        for(int k=1; k<=1000; k++)
        {
            int x1 = x , y1 = y + k; // north 
            int x2 = x , y2 = y - k; // south
            int x3 = x + k, y3 = y; // east
            int x4 = x - k, y4 = y; // west
            int x5 = x + k, y5 = y + k; // north-east
            int x6 = x - k, y6 = y + k; // north-west
            int x7 = x + k, y7 = y - k; // south-east
            int x8 = x - k, y8 = y - k; // south-west
            // all diagonal indexes are out of bounds
            if(!isValidIndex(x5,y5) && !isValidIndex(x6,y6) && !isValidIndex(x7,y7) && !isValidIndex(x8,y8))
                break;
            if(isValidIndex(x1,y1) && isValidIndex(x3,y3) && isValidIndex(x5,y5))
                ans += grid[x1][y1]*grid[x3][y3]*grid[x5][y5];
            if(isValidIndex(x1,y1) && isValidIndex(x4,y4) && isValidIndex(x6,y6))
                ans += grid[x1][y1]*grid[x4][y4]*grid[x6][y6];
            if(isValidIndex(x2,y2) && isValidIndex(x3,y3) && isValidIndex(x7,y7))
                ans += grid[x2][y2]*grid[x3][y3]*grid[x7][y7];
            if(isValidIndex(x2,y2) && isValidIndex(x4,y4) && isValidIndex(x8,y8))
                ans += grid[x2][y2]*grid[x4][y4]*grid[x8][y8];
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