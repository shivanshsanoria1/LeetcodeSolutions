class Solution {
private:
    int dfs(vector<vector<int>>& graph, vector<bool>& visited, string& s, int curr){
        if(visited[curr])
            return 0;

        visited[curr] = true;
        int maxPathLen = 0;

        for(int nei: graph[curr])
            if(s[curr] != s[nei])
                maxPathLen = max(maxPathLen, dfs(graph, visited, s, nei));
        
        return 1 + maxPathLen;
    }

public:
    // T.C.=O(n^2)
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        // build-graph
        vector<vector<int>> graph(n);
        for(int i=1; i<n; i++)
        {
            graph[i].push_back(parent[i]);
            graph[parent[i]].push_back(i);
        }

        int maxPathLen = 0;
        
        for(int i=0; i<n; i++)
        {
            vector<bool> visited(n, false);
            maxPathLen = max(maxPathLen, dfs(graph, visited, s, i));
        }

        return maxPathLen;
    }
};
// O(V + E) = O(n + n-1) = O(n)