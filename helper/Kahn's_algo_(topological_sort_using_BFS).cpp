#include <bits/stdc++.h>
using namespace std;

// returns Topo-sort of the graph and empty array if a cycle is found
vector<int> topoSort(vector<vector<int>>& graph, vector<int>& indegree){
    int V = graph.size();
    
    // push the nodes with indegree 0 in queue
    queue<int> q;
    for(int i=0; i<V; i++)
        if(indegree[i] == 0)
            q.push(i);
    
    // keep popping nodes from queue and 
    // decrement the indegree of their neighbour by 1
    // push the neighbour in queue if its indegree reaches 0
    vector<int> nums;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        nums.push_back(curr);
        
        for(int nei: graph[curr])
            if(--indegree[nei] == 0)
                q.push(nei);
    }

    // cycle-found
    if(nums.size() < V)
        nums.clear();
    
    return nums;
}

int main() {
    // num of vertices
    int V = 8; 
    // directed-edges (without cycle)
    vector<vector<int>> edges = {{5,0}, {5,2}, {2,3}, {1,3}, {4,1}, {4,0}, {6,7}};

    // directed-edges (with cycle)
    // vector<vector<int>> edges = {{0,1}, {1,2}, {2,0}};
    
    // build graph and calculate indegree for each node
    vector<vector<int>> graph(V);
    vector<int> indegree(V, 0);
    for(vector<int>& edge: edges)
    {
        int a = edge[0];
        int b = edge[1];
        graph[a].push_back(b); // edge a -> b
        indegree[b]++;
    }
    
    vector<int> nums = topoSort(graph, indegree);
    if(nums.empty())
        cout<<"Cycle found"<<endl;
    else
    {
        for(int num: nums)
            cout<<num<<" ";
        cout<<endl;   
    }

    return 0;
}

/*
# Kahn's algo.; Topological sort using BFS
# T.C.=O(V+E), S.C.=O(V)
# Topo-sort is not unique
# indegree: num of incoming edges to a vertex
# Topo-sort works only for DAG (Directed Acyclic Graph)
# if the graph contains a cycle then its 
  Topo-sort will have less than V nodes
*/