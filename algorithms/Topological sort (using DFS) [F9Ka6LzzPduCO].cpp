#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

void dfs(vector<vector<int>>& graph, vector<int>& visited, vector<int>& nums, int curr){
    if(visited[curr])
        return;
    
    visited[curr] = true;
    for(int nei: graph[curr])
        dfs(graph, visited, nums, nei);
    
    nums.push_back(curr);
}

vector<int> topoSort(vector<vector<int>>& graph){
    int V = graph.size();
    vector<int> visited(V, false);
    vector<int> nums;
    
    for(int i=0; i<V; i++)
        if(!visited[i])
            dfs(graph, visited, nums, i);
    
    reverse(nums.begin(), nums.end());
    return nums;
}

// --------------- END --------------- //

int main() {
    // num of vertices
    int V = 8; 
    // directed-edges (without cycle)
    vector<vector<int>> edges = {{5,0}, {5,2}, {2,3}, {1,3}, {4,1}, {4,0}, {6,7}};
    
    vector<vector<int>> graph(V);
    for(vector<int>& edge: edges)
    {
        int a = edge[0];
        int b = edge[1];
        graph[a].push_back(b); // edge a -> b
    }
    
    vector<int> nums = topoSort(graph);
    cout<<"Topological sort: "<<endl;
    for(int num: nums)
        cout<<num<<" ";
    cout<<endl;
    
    cout<<"---------------------"<<endl;

    return 0;
}