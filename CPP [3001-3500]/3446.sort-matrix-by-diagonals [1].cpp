class Solution {
public:
    // T.C.=O(n*n*log(n)), S.C.=O(n)
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // sort the diagonals in the Bottom-Left triangle in decreasing order
        // the middle diagonal is also included here
        for(int start=0; start<n; start++)
        {
            vector<int> temp;
            for(int i=start, j=0; i<n && j<n; i++, j++)
                temp.push_back(grid[i][j]);

            sort(temp.begin(), temp.end(), greater<int>());

            for(int i=start, j=0, k=0; i<n && j<n; i++, j++, k++)
                grid[i][j] = temp[k];
        }

        // sort the diagonals in the Top-Right triangle in increasing order
        for(int start=1; start<n; start++)
        {
            vector<int> temp;
            for(int i=0, j=start; i<n && j<n; i++, j++)
                temp.push_back(grid[i][j]);

            sort(temp.begin(), temp.end());

            for(int i=0, j=start, k=0; i<n && j<n; i++, j++, k++)
                grid[i][j] = temp[k];
        }

        return grid;
    }
};