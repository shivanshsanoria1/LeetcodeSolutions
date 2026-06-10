class Solution {
private:
    typedef pair<int, int> PI;

    int dfs(vector<vector<PI>>& graph, vector<bool>& visited, int curr){
        visited[curr] = true;
        int count = 0;

        for(auto [nei, edge]: graph[curr])
        {
            // neighbour is already visited
            if(visited[nei])
                continue;
            // found a false edge, ie, it needs to be reversed
            if(!edge)
                count++;

            count += dfs(graph, visited, nei);
        }

        return count;
    }

public:
    // T.C.=O(V*(V+E))
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<PI>> graph(n);
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            // a -> b is a true edge, ie, it exists
            graph[a].push_back({b, true});
            // b -> a is a false edge, ie, it does not exist
            graph[b].push_back({a, false});
        }

        vector<int> ans(n, 0);
        for(int i=0; i<n; i++)
        {
            vector<bool> visited(n, false);
            ans[i] = dfs(graph, visited, i);
        }

        return ans;
    }
};