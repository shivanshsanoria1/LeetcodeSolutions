class Solution {
public:
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

    int makeConnected(int n, vector<vector<int>>& connections) { // BFS
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
            auto [vertexCount, edgeCount] = bfs(graph, visited, i);
            compCount++;
            // a component with X vertices has aleast X-1 edges
            // any more edges are extra and can be removed without disconnecting the component
            extraEdges += edgeCount - (vertexCount - 1);
        }
        // to connect X components, atleast X-1 extra edges are required
        return extraEdges >= compCount - 1 ? compCount - 1 : -1;
    }
};