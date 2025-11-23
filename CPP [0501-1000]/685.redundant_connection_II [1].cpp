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
    bool isConnected(vector<vector<int>>& graph, vector<int>& indegrees, int n, int a, int b) {
        // when edge a -> b is removed, indegree of b is decremented by 1 
        indegrees[b]--;

        for(int i=1; i<=n; i++)
        {
            // only nodes with indgree 0 can be the root node
            if(indegrees[i] > 0)
                continue;
            
            vector<bool> visited(n+1, false);

            // start the dfs at ith node
            dfs(graph, a, b, visited, i);

            int visitedCount = accumulate(visited.begin() + 1, visited.end(), 0);
            // all nodes are visited
            if(visitedCount == n)
            {
                indegrees[b]++;
                return true;
            }
        }

        indegrees[b]++;
        return false;
    }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        // build graph and find the indegree of each node
        vector<vector<int>> graph(n+1);
        vector<int> indegrees(n+1, 0);
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];

            graph[a].push_back(b);
            indegrees[b]++;
        }

        vector<int> ans;
        for(int i=edges.size()-1; i>=0; i--)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            if(isConnected(graph, indegrees, n, a, b))
            {
                ans.push_back(a);
                ans.push_back(b);
                break;
            }
        }

        return ans;
    }
};