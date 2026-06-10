class Solution {
public:
    int dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr){
        if(visited[curr])
            return 0;
        visited[curr] = true;
        int count = 1;
        for(int nei: graph[curr])
            count += dfs(graph, visited, nei);
        return count;
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> graph(n);
        for(auto& edge: edges) // build graph
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        for(int ver: restricted) // mark the restricted vertices as visited
            visited[ver] = true;
        return dfs(graph, visited, 0);
    }
};