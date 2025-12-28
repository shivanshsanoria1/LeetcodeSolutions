class Solution {
private:
    void dfs(vector<int> graph[], vector<bool>& visited, vector<int>& ans, int curr){
        if(visited[curr])
            return;
        visited[curr] = true;
        ans.push_back(curr);
        for(int nei: graph[curr])
            dfs(graph, visited, ans, nei);
    }
    
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        vector<int> ans;
        for(int i=0; i<V; i++)
            if(!visited[i])
                dfs(adj, visited, ans, 0);
        return ans;
    }
    
    // T.C.=O(V + E), S.C.=O(V)
};
