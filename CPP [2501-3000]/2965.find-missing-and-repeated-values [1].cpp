class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n^2)
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<bool> isFound(n*n + 1, false);
        vector<int> ans(2, 0);

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(isFound[grid[i][j]]) // duplicate num
                    ans[0] = grid[i][j];
                else
                    isFound[grid[i][j]] = true;
            }

        for(int i=1; i<=n*n; i++)
            if(!isFound[i]) // missing num
            {
                ans[1] = i;
                break;
            }

        return ans;
    }
};
// ans[0]: duplicate num, ans[1]: missing num