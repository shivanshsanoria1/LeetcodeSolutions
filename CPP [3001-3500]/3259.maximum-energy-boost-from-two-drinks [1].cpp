class Solution {
private:
    typedef long long int lli;

    lli solve(vector<int>& numsA, vector<int>& numsB, bool type, int i, vector<vector<lli>>& dp){
        if(i >= numsA.size())
            return 0;
        
        if(dp[type][i] != -1)
            return dp[type][i];

        // remain in the same array
        lli sameArray = solve(numsA, numsB, type, i+1, dp);
        // switch to the different array
        lli switchArray = solve(numsA, numsB, !type, i+2, dp);

        dp[type][i] = (type ? numsA[i] : numsB[i]) + max(sameArray, switchArray);
        return dp[type][i]; 
    }

public:
    // T.C.=O(n), S.C.=O(2*n)
    // DP: Memoization
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n=energyDrinkA.size();

        vector<vector<lli>> dp(2, vector<lli>(n, -1));
        lli startA = solve(energyDrinkA, energyDrinkB, true, 0, dp);

        dp.resize(2, vector<lli>(n, -1));
        lli startB = solve(energyDrinkA, energyDrinkB, false, 0, dp);

        return max(startA, startB);
    }
};
// type = true: numsA[], false: numsB[]