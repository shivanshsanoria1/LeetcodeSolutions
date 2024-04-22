class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr, int dest){
        // already visited node
        if(visited[curr]) 
            return false;
        // mark the curr node as visited
        visited[curr] = true; 
        
        // found the destination node
        if(curr == dest) 
            return true;

        for(int nei: graph[curr])
            if(dfs(graph, visited, nei, dest))
                return true;

        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) { 
        vector<vector<int>> graph(n);
        // build graph
        for(auto& edge: edges) 
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b); 
            graph[b].push_back(a);
        }

        vector<bool> visited(n, false);

        return dfs(graph, visited, source, destination);
    }
};