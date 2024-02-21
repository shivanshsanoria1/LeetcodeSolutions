class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) { // T.C.=O(m + n)
        int m=grid.size(), n=grid[0].size();
        int count = 0;
        int i = 0, j = n-1;
        while(i < m && j >= 0)
        {
            if(grid[i][j] < 0)
            {
                count += m-i; // jth col have -ives from ith row
                j--;
            }
            else
                i++;
        }
        return count;
    }
};
// starting at the top-right corner