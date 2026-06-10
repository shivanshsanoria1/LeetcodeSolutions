class Solution {
private:
    int checkRows(vector<vector<int>>& grid){
        int m=grid.size(), n=grid[0].size();
        int flips = 0;
        
        for(int i=0; i<m; i++)
        {
            int left = 0, right = n-1;
            while(left < right)
            {
                if(grid[i][left] != grid[i][right])
                    flips++;
                left++;
                right--;
            }
        }
        
        return flips;
    }
    
    int checkCols(vector<vector<int>>& grid){
        int m=grid.size(), n=grid[0].size();
        int flips = 0;
        
        for(int j=0; j<n; j++)
        {
            int left = 0, right = m-1;
            while(left < right)
            {
                if(grid[left][j] != grid[right][j])
                    flips++;
                left++;
                right--;
            }
        }
        
        return flips;
    }
    
public:
    // T.C.=O(m*n), S.C.=O(1)
    int minFlips(vector<vector<int>>& grid) {
        return min(checkRows(grid), checkCols(grid));
    }
};