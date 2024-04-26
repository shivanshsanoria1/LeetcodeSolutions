class Solution {
private:
    // dfs on graph while skipping the edge a--b
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int a, int b, int curr){
        if(visited[curr])
            return;

        visited[curr] = true;

        for(int nei: graph[curr])
        {
            // skip the edge a--b
            if((curr == a && nei == b) || (curr == b && nei == a))
                continue;
            dfs(graph, visited, a, b, nei);
        }
    }

    // returns true if the graph is connected after skipping the edge a--b
    bool isGraphConnected(vector<vector<int>>& graph, int a, int b){
        int n=graph.size();
        vector<bool> visited(n, false);

        // start dfs() at vertex 0
        dfs(graph, visited, a, b, 0); 

        for(int i=0; i<n; i++)
            // unvisited vertex found
            if(!visited[i]) 
                return false;

        return true;
    }

public:
    // T.C.=O(E*(V+E))
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

        vector<vector<int>> ans;

        for(vector<int>& edge: connections)
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