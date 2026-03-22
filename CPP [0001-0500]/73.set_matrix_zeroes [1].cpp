class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) { // T.C.=O(m*n) ; S.C.=O(m+n)
        int r=matrix.size(), c=matrix[0].size();
        vector<bool> rows(r,false), cols(c,false);
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                if(matrix[i][j]==0)
                {
                    rows[i]=true;
                    cols[j]=true;
                }
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                if(rows[i] || cols[j])
                    matrix[i][j]=0;
    }
};