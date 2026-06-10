class Solution {
private:
    typedef vector<int> VEC1D; 
    typedef vector<vector<int>> VEC2D; 
    typedef vector<vector<vector<int>>> VEC3D; 

public:
    int solve(vector<vector<int>>& costs, VEC3D& dp, int i, int countA, int countB){
        int n=costs.size();
        if(countA > n/2 || countB > n/2) // no city can have more than n/2 people
            return 1e9;
        if(i == n) // index out of bounds
            return 0;
        if(dp[i][countA][countB] != -1)
            return dp[i][countA][countB];
        // ith person goes to city A
        int includeInA = costs[i][0] + solve(costs, dp, i+1, countA + 1, countB);
        // ith person goes to city B
        int includeInB = costs[i][1] + solve(costs, dp, i+1, countA, countB + 1);
        // store the min result in dp
        dp[i][countA][countB] = min(includeInA, includeInB);
        return dp[i][countA][countB]; 
    }

    int twoCitySchedCost(vector<vector<int>>& costs) { // Memoization, T.C.=O(n^3), T.C.=O(n^3)
        int n=costs.size();
        // dp of size n*(n/2+1)*(n/2+1) filled with -1's
        VEC3D dp(n, VEC2D(n/2+1, VEC1D(n/2+1, -1)));
        return solve(costs, dp, 0, 0, 0);
    }
};
