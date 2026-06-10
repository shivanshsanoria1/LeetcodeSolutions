class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(auto& op: ops)
            for(int i=0; i<op[0]; i++)
                for(int j=0; j<op[1]; j++)
                    grid[i][j]++;
        int count = 0;
        int maxVal = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] > maxVal)
                {
                    maxVal = grid[i][j];
                    count = 1;
                }
                else if(grid[i][j] == maxVal)
                    count++;
            }
        return count;
    }
};