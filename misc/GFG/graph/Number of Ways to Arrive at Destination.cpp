class Solution {
private:
    #define INF INT_MAX
    #define MOD int(1e9 + 7)
    typedef pair<int, int> PI;

public:
    int countPaths(int V, vector<vector<int>>& roads) {
        // code here
        vector<vector<PI>> graph(V);
        for(auto& road: roads) // build graph
        {
            int a = road[0];
            int b = road[1];
            int wt = road[2];
            graph[a].push_back({b, wt});
            graph[b].push_back({a, wt});
        }
        
        vector<int> dist(V, INF);
        dist[0] = 0;
        
        vector<int> ways(V, 0);
        ways[0] = 1;
        
        priority_queue<PI, vector<PI>, greater<PI>> pq; // min-heap
        pq.push({dist[0], 0});
        while(!pq.empty())
        {
            //int currDist = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            for(auto it: graph[curr])
            {
                int nei = it.first;
                int wt = it.second;
                if(dist[curr] != INF && dist[curr] + wt < dist[nei])
                {
                    dist[nei] = dist[curr] + wt;
                    ways[nei] = ways[curr];
                    pq.push({dist[nei], nei});
                }
                else if(dist[curr] != INF && dist[curr] + wt == dist[nei])
                    ways[nei] = (ways[nei] + ways[curr]) % MOD;
            }
        }
        return ways[V-1];
    }
    // Dijkstra algo.
    // T.C.=O(E*logV), S.C.=O(V^2)
};
