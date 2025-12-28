class Solution 
{
private:
    // returns number of vertices reachable from a source vertex
    int dfs(vector<int>graph[], vector<bool>& visited, int curr){
        if(visited[curr])
            return 0;
        visited[curr] = true;
        int count = 1;
        for(int nei: graph[curr])
            count += dfs(graph, visited, nei);
        return count;
    }
    
public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
        for(int i=0; i<V; i++)
        {
            vector<bool> visited(V, false);
            if(dfs(adj, visited, i) == V)
                return i;
        }
        return -1;
	}
	// T.C.=O(V*(V+E)), S.C.=O(V)
};