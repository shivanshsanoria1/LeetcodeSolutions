class Solution{
public:
    vector<vector<int>> transitiveClosure(int V, vector<vector<int>> graph)
    {
        // code here
        vector<vector<int>> ans(V, vector<int>(V, 0));
        
        for(int i=0; i<V; i++)
            for(int j=0; j<V; j++)
            {
                ans[i][j] = graph[i][j];
                // a vertex is always reachable from itself
                if(i == j)
                    ans[i][j] = 1;
            }
                
        for(int via=0; via<V; via++)
            for(int i=0; i<V; i++)
                for(int j=0; j<V; j++)
                    ans[i][j] = ans[i][j] || (ans[i][via] && ans[via][j]);
                
        return ans;
    }
    
    /*
    # Floyd Warshall algo., T.C.=O(V^3), S.C.=O(V^2)
    # The input graph is in the form adjacency matrix
    */
};
