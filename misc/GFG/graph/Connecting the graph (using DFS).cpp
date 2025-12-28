class Solution {
private:
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
            auto result = dfs(graph, visited, nei);
            int neiVertexCount = result.first;
            int neiEdgeCount = result.second;
            vertexCount += neiVertexCount;
            edgeCount += neiEdgeCount;
        }
        return {vertexCount, edgeCount};
    }
    
public:
    int Solve(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> graph(V);
        for(auto& edge: edges) // build graph
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool> visited(V, false);
        int compCount = 0; // component count
        int extraEdges = 0; // sum of extra edges for each component
        for(int i=0; i<V; i++)
        {
            if(visited[i])
                continue;
            compCount++;
            auto result = dfs(graph, visited, i);
            int vertexCount = result.first;
            int edgeCount = result.second;
            edgeCount /= 2; // since each edge was counted 2 times
            // a component with X vertices has aleast X-1 edges
            // any more edges are extra and can be removed without disconnecting the component
            extraEdges += edgeCount - (vertexCount - 1);
        }
        // to connect X components, atleast X-1 extra edges are required
        return extraEdges >= compCount - 1 ? compCount - 1 : -1;
    }
    
    // T.C.=O(V + E), S.C.=O(V)
};
