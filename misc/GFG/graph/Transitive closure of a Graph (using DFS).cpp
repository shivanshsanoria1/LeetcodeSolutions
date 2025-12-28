class Solution{
private:
    void dfs(int V, vector<vector<int>>& graph, vector<bool>& visited, int curr){
        if(visited[curr])
            return;
        visited[curr] = true;
        for(int j=0; j<V; j++)
            if(graph[curr][j] == 1)
                dfs(V, graph, visited, j);
    }

public:
    vector<vector<int>> transitiveClosure(int V, vector<vector<int>> graph)
    {
        // code here
        vector<vector<int>> ans(V, vector<int>(V, 0));
        for(int i=0; i<V; i++)
        {
            vector<bool> visited(V, false);
            dfs(V, graph, visited, i);
            for(int j=0; j<V; j++)
                if(visited[j])
                    ans[i][j] = 1;
        }
        return ans;
    }
    
    /*
    # DFS, T.C.=O(V*(V+E)), S.C.=O(V+E)
    # The input graph is in the form adjacency matrix
    */
};
