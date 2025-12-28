class Solution {
private:
    // return true if cycle is found, false otherwise
    bool dfs(vector<int> graph[], vector<bool>& visited, int par, int curr){
        visited[curr] = true;
        for(int nei: graph[curr])
        {
            // skip the neighbour which is the parent of curr vertex
            if(nei == par) 
                continue;
            // neighbour is not the parent and is already visited
            if(visited[nei])
                return true; // cycle found
            if(dfs(graph, visited, curr, nei))
                return true; // cycle found
        }
        return false; // cycle not found
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++)  
            if(!visited[i] && dfs(adj, visited, -1, i))
                return true; // cycle found
        return false; // cycle not found
    }
    
    // T.C.=O(V + E), S.C.=O(V)
};
