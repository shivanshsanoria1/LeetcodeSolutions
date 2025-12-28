class Solution {
private:
    #define INF int(1e9)
    typedef pair<int, int> PII;
    
    vector<int> dijkstra(vector<vector<PII>>& graph){
        int V = graph.size()-1;
        int src = 1; // source
        int dest = V; // destination
        
        vector<int> dist(V+1, INF);
        dist[src] = 0;
        
        // initially every node is a parent of itself
        vector<int> parent(V+1);
        for(int i=0; i<=V; i++)
            parent[i] = i;
        
        // min-heap; {dist[i], i}
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({dist[src], src});
        
        while(!pq.empty())
        {
            int curr = pq.top().second;
            pq.pop();

            // reached the 'dest' node
            if(curr == dest)
                break;
            
            // relax the edges curr--nei if possible
            for(auto it: graph[curr])
            {
                int nei = it.first;
                int wt = it.second;
                
                if(dist[curr] != INF && dist[curr] + wt < dist[nei])
                {
                    dist[nei] = dist[curr] + wt;
                    pq.push({dist[nei], nei});
                    // update the parent of 'nei'
                    parent[nei] = curr;
                }
            }
        }
        
        // 'dest' node is unreachable from 'src' node
        if(dist[dest] == INF)
            return {-1};
        
        // path from 'src' to 'dest'
        vector<int> path;
        // 0th element should be the min-distance 
        // to reach 'dest' from 'src'
        path.push_back(dist[dest]);
        // start from 'dest' and move towards the 'src' 
        // using parent[]
        int curr = V;
        path.push_back(curr);
        while(curr != src)
        {
            curr = parent[curr];
            path.push_back(curr);
        }
        
        // reverse the path from 1st index as 0th index must 
        // contain the min-distance to reach 'dest' from 'src'
        reverse(path.begin() + 1, path.end());

        return path;
    }

public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        // build graph
        vector<vector<PII>> graph(n+1);
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];
            
            graph[a].push_back({b, wt});
            graph[b].push_back({a, wt});
        }
        
        return dijkstra(graph);
    }
};
