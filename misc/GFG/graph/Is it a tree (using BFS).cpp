class Solution {
private:
    int bfs(int V, vector<unordered_set<int>>& graph, int src){
        queue<int> q;
        vector<bool> visited(V, false);
        visited[src] = true;
        q.push(src);
        int vertexCount = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            vertexCount++;
            for(int nei: graph[curr])
            {
                if(visited[nei])
                    continue;
                visited[curr] = true;
                q.push(nei);
            }
        }
        return vertexCount;
    }   

public:
    int isTree(int V, int E, vector<vector<int>> &edges) {
        // code here
        vector<unordered_set<int>> graph(V);
        int edgeCount = 0;
        for(auto& edge: edges) // build graph
        {
            int a = edge[0];
            int b = edge[1];
            if(a == b) // self loop
                return 0;
            if(graph[a].find(b) != graph[a].end()) // multiple edges
                return 0;
            if(graph[b].find(a) != graph[b].end()) // multiple edges
                return 0;
            graph[a].insert(b);
            graph[b].insert(a);
            edgeCount++;
        }
        if(edgeCount != V-1) // graph must have exactly V-1 edges
            return 0;
        return bfs(V, graph, 0) == V ? 1 : 0;
    }
    
    /*
    # T.C.=O(V+E), S.C.=O(V+E)
    # a graph is not a tree if it has self loops or multiple edges
    # a graph with V vertices is a tree if it has exactly V-1 edges and is connected
    */
};
