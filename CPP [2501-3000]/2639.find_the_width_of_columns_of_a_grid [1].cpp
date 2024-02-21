class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> ans(n);
        for(int j=0; j<n; j++)
        {
            int maxLen = 0;
            for(int i=0; i<m; i++)
            {
                string s = to_string(grid[i][j]);
                maxLen = max(maxLen, int(s.length()));
            }
            ans[j] = maxLen;
        }
        return ans;
    }
};