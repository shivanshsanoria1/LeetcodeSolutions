class Solution {
private:
    void dfs(vector<int>graph[], vector<bool>& visited, int a, int b, int curr){
        if(visited[curr])
            return;
        visited[curr] = true;
        for(int nei: graph[curr])
        {
            if((curr == a && nei == b) || (curr == b && nei == a))
                continue;
            dfs(graph, visited, a, b, nei);
        }
    }
    // returns true if graph remains connected after skipping 
    // the edge between vertices 'a' and 'b', and false otherwise
    bool isConnected(int V, vector<int>graph[], int a, int b){
        vector<bool> visited(V, false);
        dfs(graph, visited, a, b, 0);
        for(int i=0; i<V; i++)
            if(!visited[i])
                return false;
        return true;
    }
public:
    vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
        // Code here
        vector<vector<int>> criticalEdges;
        for(int i=0; i<V; i++)
            for(int nei: adj[i])
                if(i < nei && !isConnected(V, adj, i, nei))
                    criticalEdges.push_back({i, nei});
        return criticalEdges;
    }
    // T.C.=O(E*(V+E)), S.C.=O(V)
};
