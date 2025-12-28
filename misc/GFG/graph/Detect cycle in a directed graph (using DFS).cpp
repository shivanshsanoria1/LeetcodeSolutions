class Solution {
private:
    // return true if cycle is found, false otherwise
    bool dfs(vector<int> graph[], vector<bool>& visited, vector<bool>& pathVisited, int curr){
        visited[curr] = true;
        pathVisited[curr] = true;
        
        for(int nei: graph[curr])
        {
            if(visited[nei] && pathVisited[nei])
                return true; // cycle found
            if(!visited[nei] && dfs(graph, visited, pathVisited, nei))
                return true; // cycle found
        }
        
        pathVisited[curr] = false; // remove the curr vertex from pathVisited[]
        return false; // cycle not found
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);
        for(int i=0; i<V; i++)  
            if(!visited[i] && dfs(adj, visited, pathVisited, i))
                return true; // cycle found
        return false; // cycle not found
    }
    
    // T.C.=O(V + E), S.C.=O(V)
};
