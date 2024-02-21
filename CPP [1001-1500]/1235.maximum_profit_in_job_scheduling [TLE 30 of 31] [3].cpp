class Solution {
private:
    int solve(vector<vector<int>>& vec, vector<int>& dp, int i){
        // index out of bounds
        if(i >= vec.size())
            return 0;
        // solution already exists in dp
        if(dp[i] != -1)
            return dp[i];

        int startTime = vec[i][0], endTime = vec[i][1], profit = vec[i][2];

        // solve recursively excluding the curr job
        int exclude = solve(vec, dp, i+1);

        // index of the next job if the curr job is included
        int idx = i+1;
        while(idx < vec.size())
        {
            // end time of curr job <= start time of next job
            if(endTime <= vec[idx][0])
                break;
            idx++;
        }
        // solve recursively including the curr job
        int include = profit + solve(vec, dp, idx);

        // store the result in dp before returning
        dp[i] = max(include, exclude); 
        return dp[i];
    }

public:
    // T.C.=O(n*logn + n^2), S.C.=O(n)
    // Sorting + Memoization + Linear-search
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
        // dp of size n filled with -1's
        vector<int> dp(n, -1);
        return solve(vec, dp, 0);
    }
};