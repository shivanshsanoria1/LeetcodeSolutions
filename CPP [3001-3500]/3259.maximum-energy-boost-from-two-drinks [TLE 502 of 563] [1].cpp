class Solution {
private:
    typedef long long int lli;

    lli solve(vector<int>& numsA, vector<int>& numsB, bool type, int i){
        if(i >= numsA.size())
            return 0;

        // remain in the same array
        lli sameArray = solve(numsA, numsB, type, i+1);
        // switch to the different array
        lli switchArray = solve(numsA, numsB, !type, i+2);

        return (type ? numsA[i] : numsB[i]) + max(sameArray, switchArray);
    }

public:
    // T.C.=O(), S.C.=O(n)
    // Recusrion
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        lli startA = solve(energyDrinkA, energyDrinkB, true, 0);
        lli startB = solve(energyDrinkA, energyDrinkB, false, 0);

        return max(startA, startB);
    }
};
// type = true: numsA[], false: numsB[]