class Solution {
private:
    int solve(vector<int>& arr, int k, int i){
        int n=arr.size();
        int currMax = 0;
        int res = 0;
        for(int j=i; j<min(n, i+k); j++)
        {
            currMax = max(currMax, arr[j]);
            int windowSize = j-i+1;
            res = max(res, solve(arr, k, j+1) + currMax * windowSize);
        }
        return res;
    }

public:
    // Recursion
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return solve(arr, k, 0);
    }
};