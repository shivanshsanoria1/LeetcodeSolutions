class Solution {
private:
    // return true if cycle is found, false otherwise
    bool bfs(vector<int> graph[], vector<bool>& visited, int src){
        queue<pair<int, int>> q; // {curr, parent}
        q.push({src, -1});
        while(!q.empty())
        {
            int curr = q.front().first;
            int par = q.front().second;
            q.pop();
            for(int nei: graph[curr])
            {
                // skip the neighbour which is the parent of curr vertex
                if(nei == par)
                    continue;
                // neighbour is not the parent and is already visited
                if(visited[nei]) 
                    return true; // cycle found
                visited[nei] = true;
                q.push({nei, curr});
            }
        }
        return false; // cycle not found
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++)  
            if(!visited[i] && bfs(adj, visited, i))
                return true; // cycle found
        return false; // cycle not found
    }
    
    // T.C.=O(V + E), S.C.=O(V)
};
