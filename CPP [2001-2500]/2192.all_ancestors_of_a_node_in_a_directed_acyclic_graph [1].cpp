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
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto& edge: edges)
            graph[edge[1]].push_back(edge[0]);
        
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
// A <- B : A is ancestor of B