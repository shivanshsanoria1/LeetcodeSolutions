class Solution {
public:
    int dfs(unordered_map<int, vector<int>> &mp, vector<int> &informTime, int curr, int manager)
    {
        int time = 0;
        for(int sub: mp[curr])
            time = max(time, dfs(mp, informTime, sub, curr));
        return manager == -1 ? time : time + informTime[manager];
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> mp; // managerId -> {subordinates}
        for(int i=0; i<n; i++)
            mp[manager[i]].push_back(i);
        return dfs(mp, informTime, headID, -1);
    }
};
// DFS, T.C.=O(n), S.C.=O(n)