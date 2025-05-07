class Solution {
private:
    void solve(vector<vector<int>>& grid, int n, int i, int j, int& curr){
        if(n == 1)
        {
            grid[i][j] = curr--;
            return;
        }

        // quad 2 (top-left)
        solve(grid, n/2, i, j, curr);
        // quad 3 (bottom-left)
        solve(grid, n/2, i + n/2, j, curr);
        // quad 4 (bottom-right)
        solve(grid, n/2, i + n/2, j + n/2, curr);
        // quad 1 (top-right)
        solve(grid, n/2, i, j + n/2, curr);
    }

public:
    // T.C.=O(2^(2*N)), S.C.=O(??)
    vector<vector<int>> specialGrid(int N) {
        int n = 1 << N; // pow(2, N)
        int maxNum = n*n - 1; // pow(2, 2*N) - 1
        vector<vector<int>> grid(n, vector<int>(n, 0));

        solve(grid, n, 0, 0, maxNum);

        return grid;
    }
};