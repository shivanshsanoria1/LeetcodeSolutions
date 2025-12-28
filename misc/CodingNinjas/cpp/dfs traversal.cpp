void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& vec, int curr){
    if(visited[curr])
        return;
    visited[curr] = true;
    vec.push_back(curr);
    for(int nei: graph[curr])
        dfs(graph, visited, vec, nei);
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> graph(V);
    for(auto& edge: edges) // build graph
    {
        int a = edge[0];
        int b = edge[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> visited(V, false);
    vector<vector<int>> ans;
    for(int i=0; i<V; i++)
        if(!visited[i])
        {
            vector<int> vec;
            dfs(graph, visited, vec, i);
            ans.push_back(vec);
        }
    return ans;
}
