class Solution {
public:
    // returns {vertexCount, edgeCount}
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
        // since each edge is counted 2 times
        return {vertexCount, edgeCount/2};
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) { // BFS
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
            auto [vertexCount, edgeCount] = bfs(graph, visited, i);
            if(edgeCount == vertexCount*(vertexCount - 1)/2)
                ans++;
        }
        return ans;
    }
};
// a complete component with v vertices must have (v*(v-1))/2 edges