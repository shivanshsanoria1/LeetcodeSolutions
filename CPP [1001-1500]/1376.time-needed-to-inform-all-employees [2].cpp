class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) { 
        unordered_map<int, vector<int>> mp; // managerId -> {subordinates}
        for(int i=0; i<n; i++)
            mp[manager[i]].push_back(i);
        queue<pair<int, int>> q; // {employeeID, time taken by info. to reach him}
        q.push({headID, 0}); // headID does not have to wait for info.
        int totalTime = 0;
        while(!q.empty())
        {
            int size = q.size();
            int time = 0;
            while(size--)
            {
                int curr = q.front().first;
                int time = q.front().second;
                q.pop();
                totalTime = max(totalTime, time);
                for(int sub: mp[curr]) // push all the subordinates of curr in the queue
                    // informTime[curr] extra time is taken buy curr to spread info. to his subordinates
                    q.push({sub, time + informTime[curr]});
            }
        }
        return totalTime;
    }
};
// BFS, T.C.=O(n), S.C.=O(n)