class Graph {
private:
    #define INF INT_MAX
    typedef pair<int, int> PI;
    vector<vector<PI>> graph;

public:
    Graph(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for(auto& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];
            graph[a].push_back({b, wt});
        }
    }
    
    void addEdge(vector<int> edge) {
        int a = edge[0];
        int b = edge[1];
        int wt = edge[2];
        graph[a].push_back({b, wt});
    }
    
    int shortestPath(int node1, int node2) { // Dijkstra algo., T.C.=O(E*logV)
        int V = graph.size();
        vector<int> dist(V, INF);
        dist[node1] = 0;
        priority_queue<PI, vector<PI>, greater<PI>> pq; // min-heap
        pq.push({dist[node1], node1});
        while(!pq.empty())
        {
            int curr = pq.top().second;
            pq.pop();
            for(auto [nei, wt]: graph[curr])
                if(dist[curr] + wt < dist[nei])
                {
                    dist[nei] = dist[curr] + wt;
                    pq.push({dist[nei], nei});
                }
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