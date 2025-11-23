class Solution {
private:
    int solve(vector<int>& piles, bool player, int left, int right){
        if(left > right)
            return 0;
        
        // val of pile at 'left' is only counted for Alice
        int l = player ? piles[left] : 0;
        // val of pile at 'right' is only counted for Alice
        int r = player ? piles[right] : 0;

        // after picking the pile at 'left'
        l += solve(piles, !player, left + 1, right);
        // after picking the pile at 'right'
        r += solve(piles, !player, left, right - 1);

        // Alice is trying to maximize her score and 
        // Bob is trying to mminimize Alice's score
        return player ? max(l, r) : min(l, r);
    }

public:
    // T.C.=O(2^n), S.C.=O(n)
    // Recursion
    bool stoneGame(vector<int>& piles) {
        int totalSum = accumulate(piles.begin(), piles.end(), 0);
        int scoreA = solve(piles, true, 0, piles.size()-1);

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