class Solution {
public:
    // T.C.=O(m*n*(maxVal - minVal)), S.C.=O(1)
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size(), n=grid[0].size();

        int minVal = INT_MAX;
        int maxVal = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                minVal = min(minVal, grid[i][j]);
                maxVal = max(maxVal, grid[i][j]);
            }

        int minOps = INT_MAX;
        for(int finalVal = minVal; finalVal <= maxVal; finalVal++)
        {
            int ops = 0;
            bool isPossible = true;
            for(int i=0; i<m && isPossible; i++)
                for(int j=0; j<n; j++)
                {
                    int diff = abs(finalVal - grid[i][j]);
                    if(diff % x != 0)
                    {
                        isPossible = false;
                        break;
                    }
                    ops += diff/x;
                }
            
            if(isPossible)
                minOps = min(minOps, ops);
        }

        return minOps == INT_MAX ? -1 : minOps;
    }
};