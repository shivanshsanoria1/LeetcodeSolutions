class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result(rowIndex+1);
        for(int i=0; i<=rowIndex; i++)
        {
            result[i].resize(i+1); // give size of column
            result[i][0]=1; // first element of each row is 1
            result[i][i]=1; // last element of each row is 1
            for(int j=1; j<=i-1; j++)
                result[i][j]=result[i-1][j]+result[i-1][j-1];
        }
        vector<int> arr;
        arr=result[rowIndex];
        return arr;
    }
};