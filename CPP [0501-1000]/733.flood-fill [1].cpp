class Solution {
private:
    void dfs(vector<vector<int>>& image, int startColor, int newColor, int i, int j){
        int m=image.size(), n=image[0].size();
        // index out of bounds
        if(i<0 || i>=m || j<0 || j>=n) 
            return;
        // curr element is not the start color
        if(image[i][j] != startColor)
            return;
        // curr element is the new color
        if(image[i][j] == newColor)
            return;
        // fill the curr element with the new color
        image[i][j] = newColor; 

        dfs(image, startColor, newColor, i-1, j); // up
        dfs(image, startColor, newColor, i+1, j); // down
        dfs(image, startColor, newColor, i, j-1); // left
        dfs(image, startColor, newColor, i, j+1); // right
    }

public:
    // T.C.=O(m*n), S.C.=O(m*n)
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, image[sr][sc], color, sr, sc);
        return image;
    }
};