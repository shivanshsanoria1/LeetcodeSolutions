class Solution {
public:
    int bfs(vector<vector<int>>& graph, vector<bool>& visited, int src){
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
                if(visited[nei])
                    continue;
                visited[nei] = true;
                q.push(nei);
            }
        }
        return count;
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> graph(n);
        for(auto& edge: edges) // build graph
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        for(int ver: restricted) // mark the restricted vertices as visited
            visited[ver] = true;
        return bfs(graph, visited, 0);
    }
};