class Solution {
private:
    // returns true if the submatrix with top-left corner at (0, 0)  
    // and bottom-right corner at (end_i, end_j) contains 
    // equal freq of 'x' and 'y' and x > 0
    bool isSubmatrixValid(vector<vector<char>>& grid, int end_i, int end_j){
        int x = 0, y = 0;

        for(int i=0; i<=end_i; i++)
            for(int j=0; j<=end_j; j++)
            {
                if(grid[i][j] == 'X')
                    x++;
                else if(grid[i][j] == 'Y')
                    y++;
            }
        
        return x > 0 && x == y;
    }

public:
    // T.C.=O((m*n)^2), S.C.=O(1)
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int count = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(isSubmatrixValid(grid, i, j))
                    count++;
        
        return count;
    }
};