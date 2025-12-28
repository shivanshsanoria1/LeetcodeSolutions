class Solution {
private:
    // returns {vertexCount, edgeCount} starting at a source vertex
    pair<int, int> bfs(vector<vector<int>>& graph, vector<bool>& visited, int src){
        queue<int> q;
        visited[src] = true;
        q.push(src);
        int vertexCount = 0;
        int edgeCount = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            vertexCount++;
            edgeCount += graph[curr].size();
            for(int nei: graph[curr])
            {
                if(visited[nei])
                    continue;
                visited[nei] = true;
                q.push(nei);
            }
        }
        // since each edge was counted 2 times
        return {vertexCount, edgeCount / 2};
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
            auto result = bfs(graph, visited, i);
            int vertexCount = result.first;
            int edgeCount = result.second;
            // a component with X vertices has aleast X-1 edges
            // any more edges are extra and can be removed without disconnecting the component
            extraEdges += edgeCount - (vertexCount - 1);
        }
        // to connect X components, atleast X-1 extra edges are required
        return extraEdges >= compCount - 1 ? compCount - 1 : -1;
    }
    
    // T.C.=O(V + E), S.C.=O(V)
};
