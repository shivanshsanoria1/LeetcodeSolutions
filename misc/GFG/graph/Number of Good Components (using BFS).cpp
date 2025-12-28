class Solution {
private:
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
    
public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        vector<bool> visited(V+1, false);
        int ans = 0; // good component count
        for(int i=1; i<=V; i++)
        {
            if(visited[i])
                continue;
            auto result = bfs(adj, visited, i);
            int vertexCount = result.first;
            int edgeCount = result.second;
            if(edgeCount == vertexCount*(vertexCount - 1)/2)
                ans++;
        }
        return ans;
    }
    // BFS, T.C.=O(V + E), S.C.=O(V)
    // a good component with v vertices must have (v*(v-1))/2 edges
};
