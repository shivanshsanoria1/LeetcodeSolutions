class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int sum1=0, sum2=0;
        for(int i=0; i<n; i++)
        {
            sum1+=mat[i][i]; //primary diagonal sum
            sum2+=mat[i][n-i-1]; //secondary diagonal sum
        }
        if(n%2!=0) //odd num of elements in matrix
            sum2-=mat[n/2][n/2]; //remove the center element from sum2
        return sum1+sum2;
    }
};