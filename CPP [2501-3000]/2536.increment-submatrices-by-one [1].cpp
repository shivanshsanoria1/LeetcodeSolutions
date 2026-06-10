class Solution {
public:
    // T.C.=O(q*n^2), S.C.=O(1)
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // n*n matrix filled with 0's
        vector<vector<int>> mat(n, vector<int>(n, 0));

        for(vector<int>& query: queries)
        {
            int i1 = query[0], j1 = query[1];
            int i2 = query[2], j2 = query[3];

            for(int i=i1; i<=i2; i++)
                for(int j=j1; j<=j2; j++)
                    mat[i][j]++;
        }

        return mat;
    }
};