class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr) {
        if(visited[curr])
            return;

        visited[curr] = true;

        for(int nei: graph[curr])
            dfs(graph, visited, nei);
    }

public:
    // T.C.=O(n*(n + e)), S.C.=O(n + e)
    // e: size of edges[]
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // build graph
        vector<vector<int>> graph(n);
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
        }
        
        vector<vector<int>> ans(n);
        for(int i=0; i<n; i++)
        {
            vector<bool> visited(n, false);
            dfs(graph, visited, i);
            
            // any visited node j must have 
            // the starting node i as an ancestor
            for(int j=0; j<n; j++)
                if(visited[j] && j != i)
                    ans[j].push_back(i);
        }

        return ans;
    }
};
// A -> B : A is ancestor of B
// starting dfs() from any node A, 
// all the reachable nodes must have A as an ancestor