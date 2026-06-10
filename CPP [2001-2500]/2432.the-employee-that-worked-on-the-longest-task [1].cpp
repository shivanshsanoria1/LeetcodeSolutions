class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int maxTime = logs[0][1];
        int ans = logs[0][0];
        for(int i=1; i<logs.size(); i++)
        {
            int id = logs[i][0];
            int startTime = logs[i-1][1];
            int endTime = logs[i][1];
            if(endTime - startTime > maxTime)
            {
                maxTime = endTime - startTime;
                ans = id;
            }
            else if(endTime - startTime == maxTime)
                ans = min(ans, id);
        }
        return ans;
    }
};