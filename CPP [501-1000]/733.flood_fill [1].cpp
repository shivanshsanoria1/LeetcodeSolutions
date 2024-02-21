class Solution {
public:
    void dfs(vector<vector<int>>& image, int startColor, int color, int x, int y){
        int m=image.size(), n=image[0].size();
        if(x<0 || x>=m || y<0 || y>=n) // index out of bounds
            return;
        // curr element is not the start color or curr element is the new color
        if(image[x][y] != startColor || image[x][y] == color)
            return;
        image[x][y] = color; // fill the curr element with the new color
        dfs(image, startColor, color, x-1, y); // up
        dfs(image, startColor, color, x+1, y); // down
        dfs(image, startColor, color, x, y-1); // left
        dfs(image, startColor, color, x, y+1); // right
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) { // DFS
        dfs(image, image[sr][sc], color, sr, sc);
        return image;
    }
};