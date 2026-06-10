class Solution {
public:
    // returns {vertexCount, edgeCount} starting at a source vertex
    // since each edge is counted 2 times so real edgeCount is edgeCount / 2 
    pair<int, int> dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr){
        if(visited[curr])
            return {0, 0};
        visited[curr] = true;
        int vertexCount = 1;
        int edgeCount = graph[curr].size();
        for(int nei: graph[curr])
        {
            auto [neiVertexCount, neiEdgeCount] = dfs(graph, visited, nei);
            vertexCount += neiVertexCount;
            edgeCount += neiEdgeCount;
        }
        return {vertexCount, edgeCount};
    }

    int makeConnected(int n, vector<vector<int>>& connections) { // DFS
        vector<vector<int>> graph(n);
        for(auto& connection: connections) // build graph
        {
            int a = connection[0];
            int b = connection[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool> visited(n, false);
        int compCount = 0; // component count
        int extraEdges = 0; // sum of extra edges for each component
        for(int i=0; i<n; i++)
        {
            if(visited[i])
                continue;
            auto [vertexCount, edgeCount] = dfs(graph, visited, i);
            compCount++;
            edgeCount /= 2; // since each edge was counted 2 times
            // a component with X vertices has aleast X-1 edges
            // any more edges are extra and can be removed without disconnecting the component
            extraEdges += edgeCount - (vertexCount - 1);
        }
        // to connect X components, atleast X-1 extra edges are required
        return extraEdges >= compCount - 1 ? compCount - 1 : -1;
    }
};