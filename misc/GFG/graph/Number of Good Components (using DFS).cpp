class Solution {
private:
    // returns {vertexCount, edgeCount} and each edge is counted 2 times
    pair<int, int> dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr){
        if(visited[curr])
            return {0, 0};
        visited[curr] = true;
        int currVertexCount = 1;
        int currEdgeCount = graph[curr].size();
        for(int nei: graph[curr])
        {
            auto result = dfs(graph, visited, nei);
            int vertexCount = result.first;
            int edgeCount = result.second;
            currVertexCount += vertexCount;
            currEdgeCount += edgeCount;
        }
        return {currVertexCount, currEdgeCount};
    }
    
public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        vector<bool> visited(V+1, false);
        int ans = 0; // good component count
        for(int i=1; i<=V; i++)
        {
            if(visited[i])
                continue;
            auto result = dfs(adj, visited, i);
            int vertexCount = result.first;
            int edgeCount = result.second;
            // since each edge is counted 2 times
            if(edgeCount == vertexCount*(vertexCount - 1))
                ans++;
        }
        return ans;
    }
    // DFS, T.C.=O(V + E), S.C.=O(V)
    // a good component with v vertices must have (v*(v-1))/2 edges
};
