#include <bits/stdc++.h>
using namespace std;

#define INF int(1e9)

// returns the shortest path distance from source node to every other node
// and empty array if -ive weight cycle is found
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src){
    // initially distance of reaching any node 
    // from source node is assumed to be infinity
    vector<int> dist(V, INF);
    // distance of reaching source node from itself is 0
    dist[src] = 0;
    
    // relax all the edges 'V' times
    for(int r=1; r<=V; r++)
    {
        bool isRelaxationDone = false;
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];
            
            if(dist[a] != INF && dist[a] + wt < dist[b])
            {
                // relaxation still possible on the Vth iteration
                // thus a -ive wt. cycle is found
                if(r == V)
                    return {};

                dist[b] = dist[a] + wt;
                isRelaxationDone = true;
            }
        }
        // no edge relaxation is done on the rth iteration
        if(!isRelaxationDone)
            break;
    }
    
    return dist;
}

int main() {
    int V = 3; // num of vertices
    // graph without -ive weight cycle
    vector<vector<int>> edges = {{0,1,5}, {1,0,3}, {1,2,-1}, {2,0,1}};

    // graph with -ive weight cycle
    // vector<vector<int>> edges = {{0,1,5}, {1,2,-2}, {2,1,-5}};
    
    vector<int> dist = bellmanFord(V, edges, 2);

    if(dist.empty())
        cout<<"Negative weight cycle found"<<endl;
    else
    {
        for(int i=0; i<V; i++)
            cout<<i<<" -> "<<dist[i]<<endl;
    }

    return 0;
}

/*
# Bellman-Ford algo; single source shortest path
# T.C.=O(V*E), S.C.=O(V)
# edge is represented as {A,B,wt} meaning 
  directed edge from A -> B of weight wt
# works for both DG (Directed Graph) and UG (Undirected Graph)
# to make this algo. work or UG (Undirected Graph)
  just replace each undirected edge A--B with 
  2 directed edges A->B and A<-B
# works with -ive edge weights
# can detect -ive weight cycle
# relaxation of an edge A->B means that we have found 
  a shorter path to reach the node B through the node A
# relax each edge (V-1) times to get the shortest paths
# if edge relaxation is still possible on the Vth iteration, 
  then a -ive weight cycle is found
*/