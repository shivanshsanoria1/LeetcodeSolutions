class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) { // Tabulation, T.C.=O(m*n), S.C.=O(m*n)
        int m=dungeon.size(), n=dungeon[0].size();
        vector<vector<int>> dp(m+1, vector(n+1, INT_MIN));
        for(int i=m-1; i>=0; i--)
            for(int j=n-1; j>=0; j--)
            {
                if(i == m-1 && j == n-1) // bottom-right corner of dungeon
                {
                    dp[i][j] = dungeon[i][j] >= 0 ? 0 : dungeon[i][j];
                    continue;
                }
                int result = dungeon[i][j] + max(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = result >= 0 ? 0 : result;
            }
        return 1 + abs(dp[0][0]);
    }
};
/*
# fill the dp from bottom-right to top-left corner
# last row and col of dp is filled with INT_MIN's
# if the result at curr cell is +ive, reduce it to 0
  if it is -ive then just return it
*/