class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) { // T.C.=O(m*n)
        int m=matrix.size(), n=matrix[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(matrix[i][j]==target)
                    return true;
        return false;
    }
};