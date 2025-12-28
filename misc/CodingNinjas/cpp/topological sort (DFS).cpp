#include <bits/stdc++.h> 

void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& ans, int curr){
    if(visited[curr])
        return;
    visited[curr] = true;
    for(int nei: graph[curr])
        dfs(graph, visited, ans, nei);
    ans.push_back(curr);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int V, int E)  {
    // Write your code here
    vector<vector<int>> graph(V);
    for(auto& edge: edges) // build graph
    {
        int a = edge[0];
        int b = edge[1];
        graph[a].push_back(b);
    }

    vector<bool> visited(V, false);
    vector<int> ans;
    for(int i=0; i<V; i++)
        if(!visited[i])
            dfs(graph, visited, ans, i);

    reverse(ans.begin(), ans.end());
    return ans;
}

/*
# DFS
# T.C.=O(V+E), S.C.=O(V)
# Topological sort works only for DAG (Directed Acyclic Graph)
*/