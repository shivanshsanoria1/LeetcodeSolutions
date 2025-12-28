class Solution {
private:
    int dfs(int V, vector<unordered_set<int>>& graph, vector<bool>& visited, int curr){
        if(visited[curr])
            return 0;
        visited[curr] = true;
        int vertexCount = 1;
        for(int nei: graph[curr])
            vertexCount += dfs(V, graph, visited, nei);
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
        // check if graph is connected or not
        vector<bool> visited(V, false);
        return dfs(V, graph, visited, 0) == V ? 1 : 0;
    }
    
    /*
    # T.C.=O(V+E), S.C.=O(V+E)
    # a graph is not a tree if it has self loops or multiple edges
    # a graph with V vertices is a tree if it has exactly V-1 edges and is connected
    */
};
