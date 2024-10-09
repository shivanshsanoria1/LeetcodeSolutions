#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

void dfs(vector<vector<int>>& graph, vector<int>& visited, int curr){
    if(visited[curr])
        return;
    
    visited[curr] = true;
    cout<<curr<<" ";
    
    for(int nei: graph[curr])
        dfs(graph, visited, nei);
}

// --------------- END --------------- //

int main() {
    int V = 5; // vertices
    // undirected edges
    vector<vector<int>> edges = {{0, 1}, {1, 3}, {3, 0}, {4, 2}};
    
    vector<vector<int>> graph(V);
    for(vector<int>& edge: edges)
    {
        int a = edge[0];
        int b = edge[1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int src = 0; // source vertex
    cout<<"DFS starting at vertex: "<<src<<endl;
    vector<int> visited(V, false);
    dfs(graph, visited, src);
    
    cout<<endl<<"------------------"<<endl;

    return 0;
}