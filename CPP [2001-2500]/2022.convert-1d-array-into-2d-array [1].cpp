class Solution {
public:
    // T.C.=O(m*n), S.C.=O(1)
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n)
            return {};

        vector<vector<int>> ans(m, vector<int>(n));
        int idx = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                ans[i][j] = original[idx++];

        return ans;
    }
};