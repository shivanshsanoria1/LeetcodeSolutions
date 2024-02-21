class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) { //BFS, T.C.=O(n), S.C.=O(n)
        vector<vector<int>> graph(n);
        for(auto edge: edges) // build graph
        {
            graph[edge[0]].push_back(edge[1]); // edge from vertex a to b
            graph[edge[1]].push_back(edge[0]); // edge from vertex b to a
        }
        vector<bool> visited(n, false); // initially all nodes are unvisited
        queue<int> q;
        visited[source] = true; // mark the source node as visited
        q.push(source); // push the souce node in queue
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            if(curr == destination) // destination node found
                return true;
            for(auto ver: graph[curr]) // push the nodes conected to the curr node in the queue
                if(visited[ver] == false) // push only the unvisited nodes in queue
                {
                    visited[ver] = true; // mark the nodes as visited before pushing them in queue
                    q.push(ver);
                }
        }
        return false;
    }
};