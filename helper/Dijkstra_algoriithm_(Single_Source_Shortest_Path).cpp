#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

#define INF int(1e9)
typedef pair<int, int> PII;

vector<int> dijkstra(vector<vector<PII>>& graph, int src){
    int V = graph.size();
    
    // initially distance of reaching any node 
    // from source node is assumed to be infinity
    vector<int> dist(V, INF);
    // distance of reaching source node from itself is 0
    dist[src] = 0;
    
    // min-heap; {dist[i], i}
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({dist[src], src});
    
    while(!pq.empty())
    {
        int curr = pq.top().second;
        pq.pop();
        
        // relax the edges curr--nei if possible
        for(auto [nei, wt]: graph[curr])
            if(dist[curr] != INF && dist[curr] + wt < dist[nei])
            {
                dist[nei] = dist[curr] + wt;
                pq.push({dist[nei], nei});
            }
    }
    
    return dist;
}

// --------------- END --------------- //

int main() {
    int V = 3; // num of vertices
    // weighted undirected edges {a, b, wt}: a -> b of weight wt
    vector<vector<int>> edges = {{0,1,1}, {0,2,6}, {1,2,3}};
    
    // build graph
    vector<vector<PII>> graph(V);
    for(vector<int>& edge: edges)
    {
        int a = edge[0];
        int b = edge[1];
        int wt = edge[2];
        
        graph[a].push_back({b, wt});
        graph[b].push_back({a, wt});
    }
    
    int src = 2;
    vector<int> dist = dijkstra(graph, src);

    for(int i=0; i<V; i++)
        cout<<i<<" -> "<<dist[i]<<endl;

    return 0;
}

/*
# Dijkstra algo; single source shortest path
# T.C.=O(E*log(V)), S.C.=O(V)
# edge is represented as {A,B,wt} meaning 
  undirected edge between A and B of weight wt
# works for both Directed and Undirected graphs
# does not work with -ive edge weights
# gives TLE when there is a -ive weight cycle
*/