class Solution {
public:
    int solve(vector<vector<int>>& costs, int i, int countA, int countB, int costA, int costB){
        int n=costs.size();
        if(countA > n/2 || countB > n/2) // no city can have more than n/2 people
            return INT_MAX;
        if(i == n) // index out of bounds
            return costA + costB;
        // ith person goes to city A
        int includeInA = solve(costs, i+1, countA + 1, countB, costA + costs[i][0], costB);
        // ith person goes to city B
        int includeInB = solve(costs, i+1, countA, countB + 1, costA, costB + costs[i][1]);
        return min(includeInA, includeInB);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) { // Recursion, T.C.=O(2^n)
        return solve(costs, 0, 0, 0, 0, 0);
    }
};