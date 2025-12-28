class Solution
{
private:
    void dfs(vector<int> graph[], vector<bool>& visited, vector<int>& ans, int curr){
        if(visited[curr])
            return;
        visited[curr] = true;
        for(int nei: graph[curr])
            dfs(graph, visited, ans, nei);
        ans.push_back(curr);
    }

public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> visited(V, false);
        vector<int> ans;
        
        for(int i=0; i<V; i++)
            if(!visited[i])
                dfs(adj, visited, ans, i);
    
        reverse(ans.begin(), ans.end());
        return ans;
	}

    /*
    # DFS
    # T.C.=O(V+E), S.C.=O(V)
    # Topological sort works only for DAG (Directed Acyclic Graph)
    */
};
