class Solution {
private:
    typedef pair<int, int> PI;

public:
    int bfs(vector<vector<PI>> &graph, vector<bool> &visited, int ans, int v){
        queue<int> q;
        visited[v] = true; // mark the curr vertex as visited
        q.push(v);
        while(!q.empty())
        {
            int a = q.front();
            q.pop();
            for(auto ver: graph[a])
            {
                int b = ver.first;
                int r = ver.second;
                ans = min(ans, r);
                if(visited[b]) // already visited vertex
                    continue;
                visited[b] = true;
                q.push(b);
            }
        }
        return ans;
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
        return bfs(graph, visited, ans, 1); // run bfs() from vertex 1
    }
};
// just find the min weight edge in the graph