class neighborSum {
private:
    vector<vector<int>> grid;
        
public:
    neighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
    }
    
    int adjacentSum(int value) {
        int n=grid.size();
        int sum = 0;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] != value)
                    continue;
                
                int top = i-1 >= 0 ? grid[i-1][j] : 0;
                int bottom = i+1 < n ? grid[i+1][j] : 0;
                int left = j-1 >= 0 ? grid[i][j-1] : 0;
                int right = j+1 < n ? grid[i][j+1] : 0;
                
                sum += top + bottom + left + right;
                
                break;
            }
        
        return sum;
    }
    
    int diagonalSum(int value) {
        int n=grid.size();
        int sum = 0;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] != value)
                    continue;
                
                int top_left = i-1 >= 0 && j-1 >= 0 ? grid[i-1][j-1] : 0;
                int top_right = i-1 >= 0 && j+1 < n ? grid[i-1][j+1] : 0;
                int bottom_left = i+1 < n && j-1 >= 0 ? grid[i+1][j-1] : 0;
                int bottom_right = i+1 < n && j+1 < n ? grid[i+1][j+1] : 0;
                
                sum += top_left + top_right + bottom_left + bottom_right;
                
                break;
            }
        
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */