class Solution {
private:
    #define MOD int(1e9 + 7)

    int dfs(int m, int n, int move, int i, int j){
        if(move < 0)
            return 0;
        if(i < 0 || i >= m || j < 0 || j >= n)
            return 1;
        
        int up = dfs(m, n, move - 1, i-1, j);
        int down = dfs(m, n, move - 1, i+1, j);
        int left = dfs(m, n, move - 1, i, j-1);
        int right = dfs(m, n, move - 1, i, j+1);

        return (up + down + left + right) % MOD;
    }

public:
    // T.C.=O(4^maxMove), S.C.=O(maxMove), Recursion
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return dfs(m, n, maxMove, startRow, startColumn);
    }
};