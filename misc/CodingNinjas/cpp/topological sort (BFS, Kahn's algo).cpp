#include <bits/stdc++.h> 

vector<int> topologicalSort(vector<vector<int>> &edges, int V, int E)  {
    // Write your code here
    vector<vector<int>> graph(V);
    vector<int> indegrees(V, 0);
    for(auto& edge: edges) // build graph
    {
        int a = edge[0];
        int b = edge[1];
        graph[a].push_back(b);
        indegrees[b]++;
    }
    // push the vertices with indegree 0 in queue
    queue<int> q;
    for(int i=0; i<V; i++)
        if(indegrees[i] == 0)
            q.push(i);
    
    vector<int> ans;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        // decrement the indegree of neighbours of curr
        // if their indegree becomes 0 push them in queue
        for(int nei: graph[curr])
        {
            indegrees[nei]--;
            if(indegrees[nei] == 0)
                q.push(nei);
        }
    }
    return ans;
}

/*
# BFS, Kahn's algo.
# T.C.=O(V+E), S.C.=O(V)
# Topological sort works only for DAG (Directed Acyclic Graph)
# indegree: num of incoming edges to a vertex
*/
