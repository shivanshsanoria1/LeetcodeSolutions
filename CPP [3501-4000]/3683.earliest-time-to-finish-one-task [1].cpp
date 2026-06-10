class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int earliestTime(vector<vector<int>>& tasks) {
        int minTime = INT_MAX;
        for(vector<int>& task: tasks)
            minTime = min(minTime, task[0] + task[1]);

        return minTime;
    }
};