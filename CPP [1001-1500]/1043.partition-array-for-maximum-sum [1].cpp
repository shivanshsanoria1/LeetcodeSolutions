class Solution {
private:
    int solve(vector<int>& arr, int k, vector<int>& dp, int i){
        int n=arr.size();
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int currMax = 0;
        int res = 0;
        for(int j=i; j<min(n, i+k); j++)
        {
            currMax = max(currMax, arr[j]);
            int windowSize = j-i+1;
            res = max(res, solve(arr, k, dp, j+1) + currMax * windowSize);
        }

        dp[i] = res;
        return dp[i];
    }

public:
    // T.C.=O(n*k), S.C.=O(n), Memoization
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n, -1);
        return solve(arr, k, dp, 0);
    }
};