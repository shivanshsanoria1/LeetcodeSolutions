class Solution {
public:
    int solve(vector<vector<int>>& triangle, int i, int j){
        int m=triangle.size();
        if(i < 0 || i >= m) // row index out of bounds
            return INT_MAX;
        int n=triangle[i].size();
        if(j < 0 || j >= n) // col index out of bounds
            return INT_MAX;
        if(i == m-1) // last row
            return triangle[i][j];
        int down = solve(triangle, i+1, j);
        int right = solve(triangle, i+1, j+1);
        return triangle[i][j] + min(down, right);
    }

    int minimumTotal(vector<vector<int>>& triangle) { // Recursion
        int m=triangle.size();
        return solve(triangle, 0, 0);
    }
};