class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) { // T.C.=O(m*n), S.C.=O(m*n)
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> trans(n, vector<int> (m)); // transpose matrix of size n*m
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                trans[j][i] = matrix[i][j];
        return trans;
    }
};