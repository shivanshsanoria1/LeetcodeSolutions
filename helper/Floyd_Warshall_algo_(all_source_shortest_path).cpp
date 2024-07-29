#include <bits/stdc++.h>
using namespace std;

#define INF int(1e9)

vector<vector<int>> floydWahshall(int V, vector<vector<int>>& edges){
    vector<vector<int>> graph(V, vector<int>(V, INF));
    
    // dist between src and dest is 0 if they are the same
    for(int i=0; i<V; i++)
        graph[i][i] = 0;
    
    for(vector<int>& edge: edges)
    {
        int a = edge[0];
        int b = edge[1];
        int wt = edge[2];
        graph[a][b] = wt;
        graph[b][a] = wt;
    }
    
    for(int via=0; via<V; via++)
        for(int i=0; i<V; i++)
            for(int j=0; j<V; j++)
                graph[i][j] = min(graph[i][j], graph[i][via] + graph[via][j]);
    
    return graph;
}

int main() {
    int V = 5; // num of vertices
    // undirected edges of the form {a,b,wt}
    vector<vector<int>> edges = {{0,1,2}, {0,4,8}, {1,2,3}, {1,4,2}, {2,3,1}, {3,4,1}}; 
    
    vector<vector<int>> graph = floydWahshall(V, edges);
    
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

/*
# Floyd Warshall algo; all source shortest path
# T.C.=O(n^3), S.C.=O(n^2)
# works for both Directed and Undirected graphs
*/