class Solution {
private:
    bool bfs(vector<vector<int>>& graph, int src, int dest){
        int n=graph.size();
        vector<bool> visited(n, false);
        queue<int> q;

        visited[src] = true;
        q.push(src);

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            if(curr == dest)
                return true;

            for(int nei: graph[curr])
            {
                if(visited[nei])
                    continue;

                visited[nei] = true;
                q.push(nei);
            }
        }

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

        return bfs(graph, source, destination);
    }
};