class Solution
{
private:
    void bfs(int V, vector<int> graph[], vector<bool>& visited, int c, int d, bool skip, int src){
        queue<int> q;
        visited[src] = true;
        q.push(src);
        int count = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            count++;
            for(int nei: graph[curr])
            {
                // skip the edge between the vertices c and d if skip == true
                if(skip && ((curr == c && nei == d) || (curr == d && nei == c)))
                    continue;
                if(visited[nei])
                    continue;
                visited[nei] = true;
                q.push(nei);
            }
        }
    }
    
public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        // component count without skipping the edge betweeen vertices c and d
        vector<bool> visited(V, false);
        int compCount1 = 0;
        for(int i=0; i<V; i++)
        {
            if(visited[i])
                continue;
            bfs(V, adj, visited, c, d, false, i);
            compCount1++;
        }
        // reset the visited vector
        for(int i=0; i<V; i++)
            visited[i] = false;
        // component count with skipping the edge betweeen vertices c and d
        int compCount2 = 0;
        for(int i=0; i<V; i++)
        {
            if(visited[i])
                continue;
            bfs(V, adj, visited, c, d, true, i);
            compCount2++;
        }
        
        return compCount1 == compCount2 ? 0 : 1;
    }

    /*
    # BFS, T.C.=O(V+E), S.C.=O(V+E)
    # The original graph may be disconnected
    # if the component count remains unchanged without and with skipping the edge between c and d
      that means the that edge is not a bridge
    */
};
