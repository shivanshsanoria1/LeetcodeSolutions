class Solution {
private:
    #define MOD int(1e9 + 7)
    #define INF LLONG_MAX
    typedef pair<long long int, int> PI;
    typedef long long int lli;

public:
    int countPaths(int n, vector<vector<int>>& roads) { // Dijkstra algo.
        vector<vector<pair<int, int>>> graph(n);
        for(auto& road: roads) // build graph
        {
            int a = road[0];
            int b = road[1];
            int wt = road[2];
            graph[a].push_back({b, wt});
            graph[b].push_back({a, wt});
        }

        // initially 0 ways to reach every vertex
        vector<int> ways(n, 0);
        ways[0] = 1; // 1 way to reach source vertex

        // initially infinity distance to reach every vertex
        vector<lli> dist(n, INF);
        dist[0] = 0; // 0 distance to reach source vertex

        priority_queue<PI, vector<PI>, greater<PI>> pq; // min-heap, {dist, vertex}
        pq.push({dist[0], 0}); // push source vertex distance and source vertex in heap

        while(!pq.empty())
        {
            // {dist to curr vertex, curr vertex}
            auto [currDist, curr] = pq.top();
            pq.pop();
            // neighbours of curr and edge weight wt between them
            for(auto [nei, wt]: graph[curr])
            {
                // new min-dist found to reach neighbouring vertex 
                if(currDist + wt < dist[nei])
                {
                    dist[nei] = currDist + wt;
                    ways[nei] = ways[curr];
                    pq.push({dist[nei], nei});
                }
                // another min-dist found to reach neighbouring vertex
                else if(currDist + wt == dist[nei])
                    ways[nei] = (ways[nei] + ways[curr]) % MOD;
            }
        }
        return ways[n-1];
    }
};