class Solution {
public:
    void solve(vector<int>& coins, set<vector<int>>& combs, vector<int>& comb, int i, int amount){
        if(i >= coins.size()) // index out of bounds
            return;
        if(amount < 0) // reached over the target amount
            return;
        if(amount == 0) // reached the target amount
        {
            vector<int> tempComb(comb.begin(), comb.end());
            sort(tempComb.begin(), tempComb.end());
            combs.insert(tempComb);
            return;
        }
        // include coin at index i, ie, remain at the same index (so that coins[i] can possibly be chosen again)
        comb.push_back(coins[i]);
        solve(coins, combs, comb, i, amount - coins[i]);
        comb.pop_back();
        // exclude coin at index i, ie, move to the next index (so that coins[i] can never be chosen again)
        solve(coins, combs, comb, i + 1, amount);
    }

    int change(int amount, vector<int>& coins) {
        set<vector<int>> combs;
        vector<int> comb;
        solve(coins, combs, comb, 0, amount);
        return combs.size();
    }
};
// this method can give all the possible coin combinations that sum up to 'amount' 