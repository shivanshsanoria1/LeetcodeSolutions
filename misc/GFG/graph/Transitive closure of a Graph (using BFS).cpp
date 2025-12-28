class Solution{
private:
    void bfs(int V, vector<vector<int>>& graph, vector<bool>& visited, int src){
        queue<int> q;
        visited[src] = true;
        q.push(src);
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int j=0; j<V; j++)
            {
                if(graph[curr][j] == 0)
                    continue;
                if(visited[j])
                    continue;
                visited[j] = true;
                q.push(j);
            }
        }
    }

public:
    vector<vector<int>> transitiveClosure(int V, vector<vector<int>> graph)
    {
        // code here
        vector<vector<int>> ans(V, vector<int>(V, 0));
        for(int i=0; i<V; i++)
        {
            vector<bool> visited(V, false);
            bfs(V, graph, visited, i);
            for(int j=0; j<V; j++)
                if(visited[j])
                    ans[i][j] = 1;
        }
        return ans;
    }
    
    /*
    # BFS, T.C.=O(V*(V+E)), S.C.=O(V+E)
    # The input graph is in the form adjacency matrix
    */
};
