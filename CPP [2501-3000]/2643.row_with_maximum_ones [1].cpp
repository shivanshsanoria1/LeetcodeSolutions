class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        int maxSum = 0;
        int row = 0;
        for(int i=0; i<m; i++)
        {
            int sum = 0;
            for(int j=0; j<n; j++)
                sum += mat[i][j];
            if(sum > maxSum)
            {
                maxSum = sum;
                row = i;
            }
        }
        return {row, maxSum};
    }
};