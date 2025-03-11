class Solution {
public:
    // T.C.=O(m*n), S.C.=O(1)
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        bool include = true;
        vector<int> ans;

        for(int i=0; i<m; i++)
        {
            if(i % 2 == 0)
                for(int j=0; j<n; j++)
                {
                    if(include)
                        ans.push_back(grid[i][j]);
                    include = !include;
                }
            else
                for(int j=n-1; j>=0; j--)
                {
                    if(include)
                        ans.push_back(grid[i][j]);
                    include = !include;
                }
        }

        return ans;
    }
};