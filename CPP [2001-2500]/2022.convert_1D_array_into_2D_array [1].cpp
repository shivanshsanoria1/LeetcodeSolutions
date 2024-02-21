class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n) //num of elements in 1d and 2d array are unequal
            return {};
        vector<vector<int>> ans(m,vector<int> (n)); //vector of m row and n col
        int index=0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                ans[i][j]=original[index];
                index++;
            }
        return ans;
    }
};