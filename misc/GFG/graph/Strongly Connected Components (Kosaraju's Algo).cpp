class Solution
{
private:
    void dfs1(vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st, int curr){
        if(visited[curr])
            return;

        visited[curr] = true;
        for(int nei: graph[curr])
            dfs1(graph, visited, st, nei);

        st.push(curr);
    }
    
    void dfs2(vector<vector<int>>& graph, vector<bool>& visited, int curr){
        if(visited[curr])
            return;

        visited[curr] = true;
        for(int nei: graph[curr])
            dfs2(graph, visited, nei);
    }
    
public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<bool> visited(V, false);
        stack<int> st;
        for(int i=0; i<V; i++)
            dfs1(adj, visited, st, i);
        
        // Transpose graph, ie, graph with reversed edges
        vector<vector<int>> adjT(V);
        for(int i=0; i<V; i++)
        {
            visited[i] = false; // clear the visited array
            for(int nei: adj[i])
                adjT[nei].push_back(i);
        }
        
        int count = 0;
        while(!st.empty())
        {
            int curr = st.top();
            st.pop();
            if(visited[curr])
                continue;
            dfs2(adjT, visited, curr);
            count++;
        }
        return count;
    }

    // T.C.=O(V + E), S.C.=O(V + E)
};
