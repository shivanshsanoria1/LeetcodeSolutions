class Solution {
public:
    // returns {vertexCount, edgeCount} and each edge is counted 2 times
    pair<int, int> dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr){
        if(visited[curr])
            return {0, 0};
        visited[curr] = true;
        int currVertexCount = 1;
        int currEdgeCount = graph[curr].size();
        for(int nei: graph[curr])
        {
            auto [vertexCount, edgeCount] = dfs(graph, visited, nei);
            currVertexCount += vertexCount;
            currEdgeCount += edgeCount;
        }
        return {currVertexCount, currEdgeCount};
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) { // DFS
        vector<vector<int>> graph(n);
        for(auto& edge: edges) // build graph
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int ans = 0; // complete component count
        for(int i=0; i<n; i++)
        {
            if(visited[i])
                continue;
            auto [vertexCount, edgeCount] = dfs(graph, visited, i);
            // since each edge is counted 2 times
            if(edgeCount == vertexCount*(vertexCount - 1))
                ans++;
        }
        return ans;
    }
};
// a complete component with v vertices must have (v*(v-1))/2 edges