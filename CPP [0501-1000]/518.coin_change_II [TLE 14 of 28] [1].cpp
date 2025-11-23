class Solution {
public:
    int solve(vector<int>& coins, int i, int amount){
        if(i >= coins.size()) // index out of bounds
            return 0;
        if(amount < 0) // reached over the target amount
            return 0;
        if(amount == 0) // reached the target amount
            return 1;
        // include coin at index i, ie, remain at the same index (so that coins[i] can possibly be chosen again)
        int include = solve(coins, i, amount - coins[i]);
        // exclude coin at index i, ie, move to the next index (so that coins[i] can never be chosen again)
        int exclude = solve(coins, i + 1, amount);
        return include + exclude;
    }

    int change(int amount, vector<int>& coins) {
        return solve(coins, 0, amount);
    }
};