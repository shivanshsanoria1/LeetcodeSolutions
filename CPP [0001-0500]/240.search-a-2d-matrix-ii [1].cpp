class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) { //T.C.=O(m+n)
        int m=matrix.size(), n=matrix[0].size();
        int row=0, col=n-1; //start at first row and last col
        while(row<m && col>=0)
        {
            if(matrix[row][col]==target)
                return true;
            if(matrix[row][col]<target)
                row++;
            else
                col--;
        }
        return false;
    }
};