#include <bits/stdc++.h> 

typedef pair<int, int> PI; // {b, wt}
typedef pair<pair<int, int>, int> PPI; // {{a, b}, wt}
typedef pair<int, pair<int, int>> PIP; // {wt, {b, a}}

vector<PPI> calculatePrimsMST(int V, int E, vector<PPI> &edges) 
{
    // Write your code here.
    vector<vector<PI>> graph(V + 1);
    for(auto& edge: edges) // build graph
    {
        int a = edge.first.first;
        int b = edge.first.second;
        int wt = edge.second;
        graph[a].push_back({b, wt});
        graph[b].push_back({a, wt});
    }

    vector<bool> visited(V + 1, false); 
    priority_queue<PIP, vector<PIP>, greater<PIP>> pq; // min-heap
    pq.push({0, {1, -1}}); 
    vector<PPI> mst;
    while(!pq.empty())
    {
        int wt = pq.top().first;
        int curr = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();
        if(visited[curr])
            continue;
        visited[curr] = true;
        if(par != -1)
            mst.push_back({{curr, par}, wt});
        for(auto it: graph[curr])
        {
            int nei = it.first;
            int wt = it.second;
            if(visited[nei])
                continue;
            pq.push({wt, {nei, curr}});
        }
    }
    return mst;
}
// T.C.=O(E*logE), S.C.=O(E)
// vertices from 1 to V
// vertex 1 has no parent (ie, -1) and so also no edge wt from -1 to 1 (ie, 0)
// mark the curr vertex as visited before adding it to the MST 
