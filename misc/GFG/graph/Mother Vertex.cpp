class Solution 
{
private:
    void dfs(vector<int>graph[], vector<bool>& visited, int curr){
        if(visited[curr])
            return;
        visited[curr] = true;
        for(int nei: graph[curr])
            dfs(graph, visited, nei);
    }
    
public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
        vector<bool> visited(V, false);
        int mother = -1;
        for(int i=0; i<V; i++)
            if(!visited[i])
            {
                dfs(adj, visited, i);
                mother = i;
            }

        for(int i=0; i<V; i++)
            visited[i] = false;

        dfs(adj, visited, mother);

        for(int i=0; i<V; i++)
            if(!visited[i])
                return -1;
            
        return mother;
	}
	/*
	# T.C.=O(V + E), S.C.=O(V)
	# If there exists a mother vertex (or vertices), 
	  then one of the mother vertices is the last finished vertex in DFS. 
	*/
};
