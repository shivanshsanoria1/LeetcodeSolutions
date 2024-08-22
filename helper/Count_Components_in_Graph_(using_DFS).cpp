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

int getComponentCount(int V, vector<vector<int>>& graph){
    vector<int> visited(V, false);
    int componentCount = 0;
    
    for(int i=0; i<V; i++)
    {
        if(visited[i])
            continue;
        
        dfs(graph, visited, i);
        cout<<endl;
        componentCount++;
    }
    
    return componentCount;
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
    
    cout<<"Components: "<<endl;
    int componentCount = getComponentCount(V, graph);
    cout<<"Component Count = "<<componentCount<<endl;
    
    cout<<"------------------"<<endl;

    return 0;
}