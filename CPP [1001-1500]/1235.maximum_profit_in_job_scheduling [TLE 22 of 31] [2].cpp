class Solution {
private:
    int solve(vector<vector<int>>& vec, vector<vector<int>>& dp, int i, int prevIdx){
        // index out of bounds
        if(i >= vec.size())
            return 0;
        // solution already exists in dp
        if(prevIdx >= 0 && dp[i][prevIdx] != -1)
            return dp[i][prevIdx];

        int startTime = vec[i][0], endTime = vec[i][1], profit = vec[i][2];
        int prevEndTime = prevIdx >= 0 ? vec[prevIdx][1] : -1;

        int include = prevEndTime <= startTime ? profit + solve(vec, dp, i+1, i) : 0;
        int exclude = solve(vec, dp, i+1, prevIdx);
        
        // store the result in dp before returning
        if(prevIdx >= 0)
            dp[i][prevIdx] = max(include, exclude); 
        return max(include, exclude);
    }

public:
    // T.C.=O(n*logn + n^2), S.C.=O(n^2)
    // Sorting + Memoization
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> vec(n, vector<int>(3));
        for(int i=0; i<n; i++)
        {
            vec[i][0] = startTime[i];
            vec[i][1] = endTime[i];
            vec[i][2] = profit[i];
        }
        // sort each job by start time
        sort(vec.begin(), vec.end());
        // dp of size n*n filled with -1's
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(vec, dp, 0, -1);
    }
};