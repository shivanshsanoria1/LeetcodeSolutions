class Solution {
public:
    int solve(vector<vector<int>>& costs, int i, int countA, int countB){
        int n=costs.size();
        if(countA > n/2 || countB > n/2) // no city can have more than n/2 people
            return 1e9;
        if(i == n) // index out of bounds
            return 0;
        // ith person goes to city A
        int includeInA = costs[i][0] + solve(costs, i+1, countA + 1, countB);
        // ith person goes to city B
        int includeInB = costs[i][1] + solve(costs, i+1, countA, countB + 1);
        return min(includeInA, includeInB);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) { // Recursion, T.C.=O(2^n)
        return solve(costs, 0, 0, 0);
    }
};
