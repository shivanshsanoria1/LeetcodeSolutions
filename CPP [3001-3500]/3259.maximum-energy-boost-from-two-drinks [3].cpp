class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // DP: Tabulation with Space-Optimization
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n=energyDrinkA.size();

        // dpA[i-2], dpA[i-1], dpA[i]
        long long int prev2_A = energyDrinkA[0];
        long long int prev1_A = prev2_A + energyDrinkA[1];
        long long int curr_A = -1;

        // dpB[i-2], dpB[i-1], dpB[i]
        long long int prev2_B = energyDrinkB[0];
        long long int prev1_B = prev2_B + energyDrinkB[1];
        long long int curr_B = -1;

        for(int i=2; i<n; i++)
        {
            curr_A = energyDrinkA[i] + max(prev1_A, prev2_B);
            curr_B = energyDrinkB[i] + max(prev1_B, prev2_A);

            prev2_A = prev1_A;
            prev1_A = curr_A;

            prev2_B = prev1_B;
            prev1_B = curr_B;
        }

        return max(curr_A, curr_B);
    }
};