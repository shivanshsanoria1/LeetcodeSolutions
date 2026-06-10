class Solution {
public:
    // T.C.=O(m*n*(m+n)), S.C.=O(1)
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<int> ans;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                int rowMin = INT_MAX;
                for(int k=0; k<n; k++)
                    rowMin = min(rowMin, matrix[i][k]);
                
                int colMax = 0;
                for(int k=0; k<m; k++)
                    colMax = max(colMax, matrix[k][j]);
                
                if(matrix[i][j] == rowMin && matrix[i][j] == colMax)
                    ans.push_back(matrix[i][j]);
            }

        return ans;
    }
};