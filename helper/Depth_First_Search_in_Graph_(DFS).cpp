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

void dfs_starter(int V, vector<vector<int>>& graph, int src){
    vector<int> visited(V, false);
    
    dfs(graph, visited, src);
    cout<<endl;
    
    for(int i=0; i<V; i++)
    {
        if(visited[i])
            continue;
            
        dfs(graph, visited, i);
        cout<<endl;
    }
}

// --------------- END --------------- //

int main() {
    int V = 5;
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
    dfs_starter(V, graph, src);
    
    cout<<"------------------"<<endl;

    return 0;
}