class Solution {
private:
    // return true if cycle is found, false otherwise
    bool dfs(vector<int> graph[], vector<int>& colors, int curr){
        colors[curr] = 1;
        for(int nei: graph[curr])
        {
            if(colors[nei] == 1)
                return true;
            if(colors[nei] == 0 && dfs(graph, colors, nei))
                return true;
        }
        colors[curr] = 2;
        return false; // cycle not found
    }
    
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> colors(V, 0);
        for(int i=0; i<V; i++)  
            if(colors[i] == 0 && dfs(adj, colors, i))
                return true; // cycle found
        return false; // cycle not found
    }
    
    /*
    # Coloring algo., T.C.=O(V + E), S.C.=O(V)
    # 0: not processed
    # 1: processing (DFS for this vertex has started, but not finished which means that 
         all descendants (in DFS tree) of this vertex are not processed yet)
    # 2: processed (vertex and all its descendants are processed)
    */
};
