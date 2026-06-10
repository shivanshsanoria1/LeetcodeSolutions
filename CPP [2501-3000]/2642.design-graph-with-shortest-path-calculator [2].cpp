class Graph {
private:
    #define INF INT_MAX
    int V = 0; // num of vertices in graph
    vector<vector<int>> edges;

public:
    Graph(int n, vector<vector<int>>& edgs) {
        V = n;
        for(auto& edge: edgs)
        {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];
            edges.push_back({a, b, wt});
        }
    }
    
    void addEdge(vector<int> edge) {
        int a = edge[0];
        int b = edge[1];
        int wt = edge[2];
        edges.push_back({a, b, wt});
    }
    
    int shortestPath(int node1, int node2) { // Bellman-Ford algo., T.C.=O(E*V)
        vector<int> dist(V, INF);
        dist[node1] = 0;
        for(int r=1; r<=V; r++) // relax all edges V times
        {
            bool relax = false;
            for(auto& edge: edges)
            {
                int a = edge[0];
                int b = edge[1];
                int wt = edge[2];
                if(dist[a] != INF && dist[a] + wt < dist[b])
                {
                    dist[b] = dist[a] + wt;
                    relax = true;
                }
            }
            if(!relax) // no more relaxtion possible
                break;
        }
        return dist[node2] == INF ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */