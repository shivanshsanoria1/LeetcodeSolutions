class Solution {
private:
    typedef long long int lli;

public:
    long long gridGame(vector<vector<int>>& grid) { // T.C.=O(n), S.C.=O(n)
        int n=grid[0].size();
        vector<lli> preSum(n); // prefix sum for 0th row
        vector<lli> postSum(n); // postfix sum for 1th row
        preSum[0] = grid[0][0];
        for(int i=1; i<n; i++)
            preSum[i] = preSum[i-1] + grid[0][i];
        postSum[n-1] = grid[1][n-1];
        for(int i=n-2; i>=0; i--)
            postSum[i] = postSum[i+1] + grid[1][i];
        
        lli ans = LLONG_MAX;
        for(int i=0; i<n; i++)
        {
            lli rob2 = max(preSum[n-1] - preSum[i], postSum[0] - postSum[i]);
            ans = min(ans, rob2);
        }
        return ans;
    }
};

/*
# the only possibilities are robot1 moving from row 0 to row 1 at index i
# the points ganied by robot1 in doing so is preSum[i] + postSum[i]
# the points gained by robot2 is max(preSum[n-1] - preSum[i], postSum[0] - postSum[i])
# since robot1 starts first, it tries to minimize the points ganied by robot2
*/