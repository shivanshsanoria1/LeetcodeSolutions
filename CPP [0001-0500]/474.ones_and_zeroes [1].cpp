class Solution {
private:
    typedef vector<int> VEC1D;
    typedef vector<vector<int>> VEC2D;
    typedef vector<vector<vector<int>>> VEC3D;

public:
    int solve(vector<string>& strs, VEC3D &dp, int i, int m, int n){
        if(i >= strs.size()) // index out of bounds
            return 0;
        if(dp[i][m][n] != -1) // result is already calculated
            return dp[i][m][n];
        int m2 = m, n2 = n;
        for(char ch: strs[i])
        {
            if(ch == '0')
                m2--;
            else
                n2--;
        }
        // including string at index i
        int in = (m2 >= 0 && n2 >= 0) ? 1 + solve(strs, dp, i+1, m2, n2) : 0; 
        // excluding string at index i
        int ex = solve(strs, dp, i+1, m, n); 
        dp[i][m][n] = max(in, ex);
        return dp[i][m][n];
    }

    int findMaxForm(vector<string>& strs, int m, int n) { // Memoization
        // {i, m, n} 3d dp of size (strs.size())x(m+1)x(n+1) filled with -1's 
        VEC3D dp(strs.size(), VEC2D(m+1, VEC1D(n+1, -1))); 
        return solve(strs, dp, 0, m, n);
    }
};
// T.C.=O((strs.size())*(m+1)*(n+1)), S.C.=O((strs.size())*(m+1)*(n+1))