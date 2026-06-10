class Solution {
private:
    int solve(vector<vector<int>>& piles, int i, int coins){
        // we have taken k coins, so we cannot take any more coins
        if(coins == 0) 
            return 0;

        // index out of bounds, ie, no more piles left
        if(i >= piles.size())
            return 0;

        // skip the curr pile and move to the next pile
        int res = solve(piles, i+1, coins);

        // take coins (atmost 'coins') from the curr pile
        int currSum = 0;

        for(int j=0; j<piles[i].size() && coins > 0; j++)
        {
            coins--;
            currSum += piles[i][j];
            res = max(res, currSum + solve(piles, i+1, coins));
        }
        
        return res;
    }

public:
    // Recursion
    int maxValueOfCoins(vector<vector<int>>& piles, int k) { 
        return solve(piles, 0, k);
    }
};