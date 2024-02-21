class Solution {
private:
    typedef pair<int, int> PI;

public:
    void dfs(vector<vector<PI>> &graph, vector<bool> &visited, int &ans, int curr){
        if(visited[curr]) // visited vertex
            return;
        visited[curr] = true; // mark the curr vertex as visited
        for(auto ver: graph[curr])
        {
            int b = ver.first;
            int r = ver.second;
            ans = min(ans, r);
            dfs(graph, visited, ans, b);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<PI>> graph(n+1);
        for(auto road: roads) // build graph
        {
            int a = road[0]; // city a
            int b = road[1]; // city b
            int r = road[2]; // road r between cities a and b
            graph[a].push_back({b, r}); // a -> b, edge weight = r
            graph[b].push_back({a, r}); // b -> a, edge weight = r
        }

        vector<bool> visited(n+1, false);
        int ans = INT_MAX;
        dfs(graph, visited, ans, 1); // run dfs() from vertex 1
        return ans;
    }
};
// just find the min weight edge in the graph