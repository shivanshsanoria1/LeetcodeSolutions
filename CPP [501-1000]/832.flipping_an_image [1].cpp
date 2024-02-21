class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        vector<vector<int>> ans(n,vector<int>(n));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) //flip horizontally ,ie, reverse each row
                ans[i][j]=image[i][n-1-j];
            for(int j=0; j<n; j++) //invert each element
                ans[i][j]= !ans[i][j];
        }
        return ans;
    }
};