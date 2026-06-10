class Solution {
private:
    int solve(vector<vector<int>>& vec, int i, int prevEndTime){
        if(i >= vec.size())
            return 0;
        int startTime = vec[i][0], endTime = vec[i][1], profit = vec[i][2];
        int include = prevEndTime <= startTime ? profit + solve(vec, i+1, endTime) : 0;
        int exclude = solve(vec, i+1, prevEndTime);
        return max(include, exclude);
    }

public:
    // T.C.=O(2^n)
    // Sorting + Recursion
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
        return solve(vec, 0, -1);
    }
};