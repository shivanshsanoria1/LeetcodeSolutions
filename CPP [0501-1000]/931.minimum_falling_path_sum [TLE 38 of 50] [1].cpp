class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j){
        int n=matrix.size();
        if(i < 0 || i >= n || j < 0 || j >= n) // index out of bounds
            return INT_MAX;
        int down = solve(matrix, i+1, j);
        int left = solve(matrix, i+1, j-1);
        int right = solve(matrix, i+1, j+1);
        int minVal = min(down, min(left, right));
        if(minVal == INT_MAX) // reset min value
            minVal = 0;
        return matrix[i][j] + minVal;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) { // Recursion, T.C.=O(n*2^n)
        int n=matrix.size();
        int ans = INT_MAX;
        for(int j=0; j<n; j++) // 0th row
            ans = min(ans, solve(matrix, 0, j));
        return ans;
    }
};