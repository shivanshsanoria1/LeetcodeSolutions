class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(auto& ind: indices)
        {
            for(int j=0; j<n; j++)
                grid[ind[0]][j]++;
            for(int i=0; i<m; i++)
                grid[i][ind[1]]++;
        }

        int count = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] % 2 == 1)
                    count++;
        return count;
    }
};