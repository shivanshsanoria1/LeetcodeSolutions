class Solution {
private:
    int solve(vector<int>& piles, bool player, int i, int m){
        int n=piles.size();
        if(i >= n)
            return 0;

        int sum = 0;
        int scoreA = player ? 0 : INT_MAX;

        for(int x=1; x <= 2*m && i+x-1 < n; x++)
        {
            sum += piles[i+x-1];
            // Alice is trying to maxmize her score
            if(player) 
                scoreA = max(scoreA, sum + solve(piles, !player, i+x, max(m, x)));
            // Bob is tyring to minimize Alice's score
            else 
                scoreA = min(scoreA, solve(piles, !player, i+x, max(m, x)));
        }

        return scoreA;
    }

public:
    // T.C.=O(??), S.C.=O(n)
    // Recursion
    int stoneGameII(vector<int>& piles) {
        return solve(piles, true, 0, 1);
    }
};
// player = true: Alice, false: Bob