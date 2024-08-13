#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

void bfs(vector<vector<int>>& graph, vector<int>& visited, int src){
    queue<int> q;
    visited[src] = true;
    q.push(src);
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";
        
        for(int nei: graph[curr])
        {
            if(visited[nei])
                continue;
                
            visited[nei] = true;
            q.push(nei);
        }
    }
}

void bfs_starter(int V, vector<vector<int>>& graph, int src){
    vector<int> visited(V, false);
    
    bfs(graph, visited, src);
    cout<<endl;
    
    for(int i=0; i<V; i++)
    {
        if(visited[i])
            continue;
            
        bfs(graph, visited, i);
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
    
    int src = 2; // source vertex
    cout<<"BFS starting at vertex: "<<src<<endl;
    bfs_starter(V, graph, src);
    
    cout<<"------------------"<<endl;

    return 0;
}