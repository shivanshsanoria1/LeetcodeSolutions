class Solution {
public:
    // dfs on graph while skipping the edge a--b
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int a, int b, int v){
        if(visited[v])
            return;
        visited[v] = true;
        for(int nei: graph[v])
        {
            // skip the edge a--b
            if((v == a && nei == b) || (v == b && nei == a))
                continue;
            dfs(graph, visited, a, b, nei);
        }
    }

    // returns true if the graph is connected after skipping the edge a--b
    bool isGraphConnected(vector<vector<int>>& graph, int a, int b){
        int n=graph.size();
        vector<bool> visited(n, false);
        dfs(graph, visited, a, b, 0); // start dfs() at vertex 0
        for(int i=0; i<n; i++)
            if(!visited[i]) // unvisited vertex left
                return false;
        return true;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(auto& edge: connections) // build graph
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<vector<int>> ans;
        for(auto& edge: connections)
        {
            int a = edge[0];
            int b = edge[1];
            // graph becomes disconnected after skipping the edge a--b
            if(!isGraphConnected(graph, a, b))
                ans.push_back({a, b});
        }
        return ans;
    }
};