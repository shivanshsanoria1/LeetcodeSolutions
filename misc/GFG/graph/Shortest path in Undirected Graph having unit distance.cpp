class Solution {
private:
    void bfs(vector<vector<int>>& graph, vector<int>& dist, int src){
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int nei: graph[curr])
            {
                if(dist[nei] != -1)
                    continue;
                dist[nei] = dist[curr] + 1;
                q.push(nei);
            }
        }
    }
    
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int V, int E, int src){
        // code here
        vector<vector<int>> graph(V);
        for(auto& edge: edges) // build graph
        {
            int a = edge[0]; 
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        vector<int> dist(V, -1);
        bfs(graph, dist, src);
        
        return dist;
    }
};
