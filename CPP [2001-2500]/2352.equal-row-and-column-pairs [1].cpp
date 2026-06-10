class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) { // T.C.=O(n^3), S.C.=O(1)
        int n=grid.size();
        int count = 0;
        for(int r=0; r<n; r++)
            for(int j=0; j<n; j++)
            {
                bool flag = true;
                for(int i=0; i<n; i++)
                    if(grid[i][j] != grid[r][i])
                    {
                        flag = false;
                        break;
                    }
                if(flag)
                    count++;
            }
        return count;
    }
};