class Solution {
private:
    int solve(vector<int>& piles, bool player, int i, int m, vector<vector<int>>& dpA, vector<vector<int>>& dpB){
        int n=piles.size();
        if(i >= n)
            return 0;
        
        if(player && dpA[i][m] != -1)
            return dpA[i][m];
        
        if(!player && dpB[i][m] != -1)
            return dpB[i][m];

        int sum = 0;
        int scoreA = player ? 0 : INT_MAX;

        for(int x=1; x <= 2*m && i+x-1 < n; x++)
        {
            sum += piles[i+x-1];
            // Alice is trying to maxmize her score
            if(player) 
                scoreA = max(scoreA, sum + solve(piles, !player, i+x, max(m, x), dpA, dpB));
            // Bob is tyring to minimize Alice's score
            else 
                scoreA = min(scoreA, solve(piles, !player, i+x, max(m, x), dpA, dpB));
        }

        if(player)
            dpA[i][m] = scoreA;
        else
            dpB[i][m] = scoreA;

        return player ? dpA[i][m] : dpB[i][m];
    }

public:
    // T.C.=O(n^2), S.C.=O(2*n^2)
    // DP: Memoization
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dpA(n, vector<int>(n+1, -1));
        vector<vector<int>> dpB(n, vector<int>(n+1, -1));

        return solve(piles, true, 0, 1, dpA, dpB);
    }
};
// player = true: Alice, false: Bob