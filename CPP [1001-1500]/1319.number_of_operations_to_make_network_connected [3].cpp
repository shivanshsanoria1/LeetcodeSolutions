class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr){
        if(visited[curr])
            return;
        visited[curr] = true;
        for(int nei: graph[curr])
            dfs(graph, visited, nei);
    }

    int makeConnected(int n, vector<vector<int>>& connections) { // DFS
        // to connect all the n vertices of the graph atleast n-1 edges are required
        if(connections.size() < n-1)
            return -1;
        vector<vector<int>> graph(n);
        for(auto& connection: connections) // build graph
        {
            int a = connection[0];
            int b = connection[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool> visited(n, false);
        int compCount = 0; // component count
        for(int i=0; i<n; i++)
            if(!visited[i])
            {
                dfs(graph, visited, i);
                compCount++;
            }
        // to connect X components, atleast X-1 extra edges are required
        return compCount - 1;
    }
};