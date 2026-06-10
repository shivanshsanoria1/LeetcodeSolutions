class Solution {
public:
    // T.C.=O(n), S.C.=O(2*n)
    // DP: Tabulation
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n=energyDrinkA.size();
        vector<long long int> dpA(n);
        vector<long long int> dpB(n);

        dpA[0] = energyDrinkA[0];
        dpA[1] = dpA[0] + energyDrinkA[1];
        dpB[0] = energyDrinkB[0];
        dpB[1] = dpB[0] + energyDrinkB[1];

        for(int i=2; i<n; i++)
        {
            dpA[i] = energyDrinkA[i] + max(dpA[i-1], dpB[i-2]);
            dpB[i] = energyDrinkB[i] + max(dpB[i-1], dpA[i-2]);
        }

        return max(dpA[n-1], dpB[n-1]);
    }
};