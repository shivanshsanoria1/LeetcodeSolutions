class Solution {
private:
    void dfs(int V, vector<int>graph[], vector<bool>& visited, int curr){
        if(visited[curr])
            return;
        visited[curr] = true;
        for(int nei: graph[curr])
            dfs(V, graph, visited, nei);
    }
    
    // returns true if the graph has only 1 component or in case of multiple components
    // either there are no edges at all or 1 component has all the edges
    bool isConnected(int V, vector<int>graph[]){
        vector<bool> visited(V, false);
        // find a vertex with degree > 0
        int start = -1;
        for(int i=0; i<V; i++)
            if(graph[i].size() > 0)
            {
                start = i;
                break;
            }
        // all vertices have degree 0, ie, no edges in graph
        if(start == -1) 
            return true;
        dfs(V, graph, visited, start);
        // check if there is any unvisited vertex left with degree > 0 
        for(int i=0; i<V; i++)
            if(!visited[i] && graph[i].size() > 0)
                return false;
        return true;
    }
    
public:
	int isEularCircuit(int V, vector<int>adj[]){
        // Code here
        if(!isConnected(V, adj)) // Non-Eular graph
            return 0;
        int oddDegreeCount = 0;
        for(int i=0; i<V; i++)
            if(adj[i].size() % 2 == 1)
                oddDegreeCount++;
        if(oddDegreeCount == 0) // Euler Circuit
            return 2;
        if(oddDegreeCount == 2) // Euler Path
            return 1;
        return 0; // Non-Eular graph
	}
	
	/*
	# T.C.=O(V+E), S.C.=O(V+E)
    # The graph may be disconnected
	# 0: Non-Eular graph, 1: Eular Path, 2: Euler Circuit
	# oddDegreeCount = 0 -> Euler Circuit
	# oddDegreeCount = 1 -> not possible 
	  (since, The number of vertices with odd degree in a graph is even)
	# oddDegreeCount = 2 -> Euler path
	# oddDegreeCount > 2 -> non-Eular graph
	*/
};
