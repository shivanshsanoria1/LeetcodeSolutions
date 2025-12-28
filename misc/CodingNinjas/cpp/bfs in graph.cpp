#include <bits/stdc++.h> 

void bfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& ans, int src){
    queue<int> q;
    visited[src] = true;
    q.push(src);
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(int nei: graph[curr])
        {
            if(visited[nei])
                continue;
            visited[nei] = true;
            q.push(nei);
        }
    }
}

vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<vector<int>> graph(V);
    for(auto& edge: edges) // build graph
    {
        int a = edge.first;
        int b = edge.second;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i=0; i<V; i++) 
        sort(graph[i].begin(), graph[i].end());
        
    vector<bool> visited(V, false);
    vector<int> ans;
    for(int i=0; i<V; i++)
        if(!visited[i])
            bfs(graph, visited, ans, i);
    return ans;
}
