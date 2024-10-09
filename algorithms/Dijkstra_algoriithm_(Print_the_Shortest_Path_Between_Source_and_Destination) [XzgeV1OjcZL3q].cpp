#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

#define INF int(1e9)
typedef pair<int, int> PII;

vector<int> dijkstra(vector<vector<PII>>& graph, int src, int dest){
    int V = graph.size();
    
    // initially every node is a parent of itself
    vector<int> parent(V);
    for(int i=0; i<V; i++)
        parent[i] = i;
    
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
        
        // relax the edge between curr and nei (if possible)
        for(auto [nei, wt]: graph[curr])
            if(dist[curr] != INF && dist[curr] + wt < dist[nei])
            {
                dist[nei] = dist[curr] + wt;
                pq.push({dist[nei], nei});
                // curr is the new parent of nei
                parent[nei] = curr;
            }
    }
    
    // cannot reach the 'dest' from 'src'
    if(dist[dest] == INF)
        return {-1};
    
    vector<int> path;
    for(int curr = dest; curr != src; curr = parent[curr])
        path.push_back(curr);
    path.push_back(src);

    reverse(path.begin(), path.end());
    
    return path;
}

// --------------- END --------------- //

int main() {
    int V = 5; // num of vertices
    // weighted undirected edges {a, b, wt}: a -- b of weight wt
    vector<vector<int>> edges = {{0,1,2}, {1,4,5}, {1,2,4}, {0,3,1}, {3,2,3}, {2,4,1}};
    
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
    
    int src = 0; // source
    int dest = 4; // destination
    vector<int> path = dijkstra(graph, src, dest);
    
    if(path.size() == 1 && path[0] == -1)
        cout<<"Cannot reach from "<<src<<" to "<<dest<<endl;
    else
    {
        cout<<"Shortest path from "<<src<<" to "<<dest<<": "<<endl;
        for(int curr: path)
            cout<<curr<<" ";
        cout<<endl;
    }
    
    cout<<endl<<"--------------------"<<endl;

    return 0;
}
