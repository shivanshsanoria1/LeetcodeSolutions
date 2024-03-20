class Solution {
private:
    void dfs(vector<vector<int>>& graph, int a, int b, vector<bool>& visited, int curr) {
        if(visited[curr])
            return;
        visited[curr] = true;

        for(int nei: graph[curr])
        {
            // skip the edge a -> b
            if(curr == a && nei == b)
                continue;
            dfs(graph, a, b, visited, nei);
        }
    }

    // returns true if the graph remains connected
    // when the edge a -> b is ignored
    bool isConnected(vector<vector<int>>& graph, int n, int a, int b) {
        for(int i=1; i<=n; i++)
        {
            vector<bool> visited(n+1, false);

            // start the dfs at ith node
            dfs(graph, a, b, visited, i);

            int visitedCount = accumulate(visited.begin() + 1, visited.end(), 0);
            // all nodes are visited
            if(visitedCount == n)
                return true;
        }

        return false;
    }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        // build graph
        vector<vector<int>> graph(n+1);
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
        }

        vector<int> ans;
        for(int i=edges.size()-1; i>=0; i--)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            if(isConnected(graph, n, a, b))
            {
                ans.push_back(a);
                ans.push_back(b);
                break;
            }
        }

        return ans;
    }
};