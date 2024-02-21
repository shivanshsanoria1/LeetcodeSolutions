class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr, int destination)
    {
        if(curr == destination) // found destination node
            return true;
        if(visited[curr] == true) // already visited node found and it is not the destination node
            return false;
        visited[curr] = true; // mark the curr node as visited
        for(auto ver: graph[curr]) // check for all the nodes connected to the curr node
            if(dfs(graph, visited, ver, destination) == true)
                return true;
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) { //DFS, T.C.=O(n), S.C.=O(n)
        vector<vector<int>> graph(n);
        for(auto edge: edges) // build graph
        {
            graph[edge[0]].push_back(edge[1]); // edge from vertex a to b
            graph[edge[1]].push_back(edge[0]); // edge from vertex b to a
        }
        vector<bool> visited(n, false); // initially all nodes are unvisited
        return dfs(graph, visited, source, destination);
    }
};