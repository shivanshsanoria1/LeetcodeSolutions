class Solution {
private:
    // returns the index of the first job whose start time >= end time of the job at index i
    // and -1 if no such job is found
    int findNextIdx(vector<vector<int>>& vec, int i){
        int left = i+1, right = vec.size()-1;
        int currEndTime = vec[i][1];
        int idx = -1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            int nextStartTime = vec[mid][0]; 
            // move to the left-subarray
            if(nextStartTime >= currEndTime)
            {
                idx = mid;
                right = mid - 1;
            }
            // move to the right-subarray
            else
                left = mid + 1;
        }
        return idx;
    }

    int solve(vector<vector<int>>& vec, vector<int>& dp, int i){
        // index out of bounds
        if(i >= vec.size() || i < 0)
            return 0;
        // solution already exists in dp
        if(dp[i] != -1)
            return dp[i];

        int startTime = vec[i][0], endTime = vec[i][1], profit = vec[i][2];

        // solve recursively excluding the curr job
        int exclude = solve(vec, dp, i+1);
        // solve recursively including the curr job
        int include = profit + solve(vec, dp, findNextIdx(vec, i));

        // store the result in dp before returning
        dp[i] = max(include, exclude); 
        return dp[i];
    }

public:
    // T.C.=O(n*logn + n*logn), S.C.=O(n)
    // Sorting + Memoization + Binary-search
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