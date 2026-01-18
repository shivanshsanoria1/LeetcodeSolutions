#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

void bfs(vector<vector<int>>& graph, int src){
    int V=graph.size();
    vector<bool> visited(V, false);
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
    cout<<"BFS starting at vertex: "<<src<<endl;
    bfs(graph, src);
    
    cout<<endl<<"------------------"<<endl;

    return 0;
}