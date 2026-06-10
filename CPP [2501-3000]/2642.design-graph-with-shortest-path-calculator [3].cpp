class Graph {
private:
    #define INF int(1e9)
    vector<vector<int>> graph;

public:
    Graph(int n, vector<vector<int>>& edges) { // Floyd-Warshall algo., T.C.=O(V^3)
        graph.resize(n, vector<int>(n, INF));

        for(auto& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];
            graph[a][b] = wt;
        }

        for(int i=0; i<n; i++)
            graph[i][i] = 0;

        for(int via=0; via<n; via++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    graph[i][j] = min(graph[i][j], graph[i][via] + graph[via][j]);
    }
    
    void addEdge(vector<int> edge) {
        int a = edge[0];
        int b = edge[1];
        int wt = edge[2];

        int n=graph.size();
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                graph[i][j] = min(graph[i][j], graph[i][a] + graph[b][j] + wt);
    }
    
    int shortestPath(int node1, int node2) {
        return graph[node1][node2] == INF ? -1 : graph[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */