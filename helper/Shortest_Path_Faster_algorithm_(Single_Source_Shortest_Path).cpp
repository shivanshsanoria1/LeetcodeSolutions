#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

#define INF int(1e9)
typedef pair<int, int> PII;

vector<int> shortestPathFaster(vector<vector<PII>>& graph, int src){
    int V = graph.size();
    
    // initially distance of reaching any node 
    // from source node is assumed to be infinity
    vector<int> dist(V, INF);
    // distance of reaching source node from itself is 0
    dist[src] = 0;
    
    queue<int> q;
    vector<bool> isInQueue(V, false);
    q.push(src);
    isInQueue[src] = true;
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        isInQueue[curr] = false;
        
        for(auto [nei, wt]: graph[curr])
            if(dist[curr] + wt < dist[nei])
            {
                dist[nei] = dist[curr] + wt;

                if(isInQueue[nei])
                    continue;

                q.push(nei);
                isInQueue[nei] = true;
            }
    }
    
    return dist;
}

// --------------- END --------------- //

int main() {
    int V = 3; // num of vertices
    // weighted directed edges {a, b, wt}: a -> b of weight wt
    // graph without -ive weight cycle
    vector<vector<int>> edges = {{0,1,5}, {1,0,3}, {1,2,-1}, {2,0,1}};
    
    vector<vector<PII>> graph(V);
    for(vector<int>& edge: edges)
    {
        int a = edge[0];
        int b = edge[1];
        int wt = edge[2];
        
        graph[a].push_back({b, wt});
    }
    
    int src= 2;
    vector<int> dist = shortestPathFaster(graph, src);

    for(int i=0; i<V; i++)
        cout<<i<<" -> "<<dist[i]<<endl;

    return 0;
}

/*
# SPFA (Shortest Path Faster Algo.)
# T.C.=O(V*E), S.C.=O(V + E)
# SPFA is a improvement of Bellman Ford algo.
# T.C. of both are the same but SPFA has a better run-time
# Unlike Bellman Ford, SPFA does not work for graph with -ive wt. cycle
*/