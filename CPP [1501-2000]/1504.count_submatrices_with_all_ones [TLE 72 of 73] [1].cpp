class Solution {
private:
    // returns true if the submatrix with top-left corner at (i1, j1) and 
    // bottom-right corner at (i2, j2) is filled with all 1's
    bool hasAllOnes(vector<vector<int>>& mat, int i1, int j1, int i2, int j2) {
        int m=mat.size(), n=mat[0].size();
        for(int i=i1; i<=i2; i++)
            for(int j=j1; j<=j2; j++)
                if(mat[i][j] == 0)
                    return false;
        return true;
    }

public:
    // T.C.=O((m*n)^3), S.C.=O(1)
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        int count = 0;

        for(int i1=0; i1<m; i1++)
            for(int j1=0; j1<n; j1++)
            {
                if(mat[i1][j1] == 0)
                    continue;
                for(int i2=i1; i2<m; i2++)
                    for(int j2=j1; j2<n; j2++)
                    {
                        if(!hasAllOnes(mat, i1, j1, i2, j2))
                            break;
                        count++;
                    }
            }

        return count;
    }
};