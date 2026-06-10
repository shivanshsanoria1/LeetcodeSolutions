class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) { // T.C.=O(m*n*(m+n)), S.C.=O(1)
        int m=mat.size(), n=mat[0].size();
        int count = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 0)
                    continue;

                int rowSum = 0;
                for(int k=0; k<n; k++) // ith row sum
                    rowSum += mat[i][k];
                if(rowSum > 1)
                    break;

                int colSum = 0;
                for(int k=0; k<m; k++) // jth col sum
                    colSum += mat[k][j];
                if(colSum > 1)
                    break;
                
                count++;
            }
        return count;
    }
};