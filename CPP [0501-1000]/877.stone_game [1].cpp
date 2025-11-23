class Solution {
private:
    int solve(vector<int>& piles, bool player, int left, int right, vector<vector<int>>& dpA, vector<vector<int>>& dpB){
        if(left > right)
            return 0;
        
        if(player && dpA[left][right] != -1)
            return dpA[left][right];
        
        if(!player && dpB[left][right] != -1)
            return dpB[left][right];
        
        // val of pile at 'left' is only counted for Alice
        int l = player ? piles[left] : 0;
        // val of pile at 'right' is only counted for Alice
        int r = player ? piles[right] : 0;

        // after picking the pile at 'left'
        l += solve(piles, !player, left + 1, right, dpA, dpB);
        // after picking the pile at 'right'
        r += solve(piles, !player, left, right - 1, dpA, dpB);

        // Alice is trying to maximize her score
        if(player) 
            dpA[left][right] = max(l, r);
        // Bob is trying to mminimize Alice's score
        else
            dpB[left][right] = min(l, r);

        return player ? dpA[left][right] : dpB[left][right];
    }

public:
    // T.C.=O(n^2), S.C.=O(2*n^2)
    // DP: Memoization
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dpA(n, vector<int>(n, -1));
        vector<vector<int>> dpB(n, vector<int>(n, -1));

        int totalSum = accumulate(piles.begin(), piles.end(), 0);
        int scoreA = solve(piles, true, 0, n-1, dpA, dpB);

        return 2*scoreA > totalSum;
    }
};
/*
# player = true: Alice, false: Bob
# return true if:
  scoreA > scoreB
  scoreA > totalSum - scoreA
  2*scoreA > totalSum
*/