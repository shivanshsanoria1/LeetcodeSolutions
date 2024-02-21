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
        dfs(graph, visited, a, b, 1); // start dfs() at vertex 1
        for(int i=1; i<n; i++)
            if(!visited[i]) // unvisited vertex left
                return false;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) { // T.C.=O(n^2), S.C.=O(n)
        int n=edges.size();
        vector<vector<int>> graph(n+1);
        for(auto& edge: edges) // build graph
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=n-1; i>=0; i--)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            if(isGraphConnected(graph, a, b))
                return {a, b};
        }
        return {};
    }
};