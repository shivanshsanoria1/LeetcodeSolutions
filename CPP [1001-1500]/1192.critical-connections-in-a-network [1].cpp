class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& bridges, vector<int>& visitTime, vector<int>& minTime, int& time, int curr, int parent){
        // already visited node
        if(visitTime[curr] != -1)
            return;
        
        time++;
        visitTime[curr] = time;
        minTime[curr] = time;

        for(int nei: graph[curr])
        {
            if(nei == parent)
                continue;

            dfs(graph, bridges, visitTime, minTime, time, nei, curr);

            minTime[curr] = min(minTime[curr], minTime[nei]);

            if(minTime[nei] > visitTime[curr])
                bridges.push_back({curr, nei});
        }
    }

public:
    // T.C.=O(V+E)
    // Tarjan's algo.
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // build graph
        vector<vector<int>> graph(n);
        for(vector<int>& edge: connections)
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> visitTime(n, -1);
        vector<int> minTime(n, -1);
        int time = 0;

        vector<vector<int>> bridges;

        dfs(graph, bridges, visitTime, minTime, time, 0, -1);

        return bridges;
    }
};