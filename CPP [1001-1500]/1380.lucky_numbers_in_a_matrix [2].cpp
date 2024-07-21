class Solution {
public:
    // T.C.=O(m*n), S.C.=O(m + n)
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();

        vector<int> rowMins(m, INT_MAX);
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                rowMins[i] = min(rowMins[i], matrix[i][j]);

        vector<int> colMaxs(n, 0);
        for(int j=0; j<n; j++)
            for(int i=0; i<m; i++)
                colMaxs[j] = max(colMaxs[j], matrix[i][j]);

        vector<int> ans;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(matrix[i][j] == rowMins[i] && matrix[i][j] == colMaxs[j])
                    ans.push_back(matrix[i][j]);
        
        return ans;
    }
};