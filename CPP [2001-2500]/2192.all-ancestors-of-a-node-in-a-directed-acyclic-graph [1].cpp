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
        // build a graph with reversed edges
        vector<vector<int>> graph(n);
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            graph[b].push_back(a);
        }
        
        vector<vector<int>> ans(n);
        for(int i=0; i<n; i++)
        {
            vector<bool> visited(n, false);
            dfs(graph, visited, i);
            
            for(int j=0; j<n; j++)
                if(visited[j] && j != i)
                    ans[i].push_back(j);
        }

        return ans;
    }
};
// initially, A -> B : A is ancestor of B
// after reversing the edges, A <- B : A is ancestor of B