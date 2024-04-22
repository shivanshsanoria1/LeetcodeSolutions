class Solution {
private:
    #define INF INT_MAX
    typedef pair<int, int> PII;

    void dijkstra(vector<vector<PII>>& graph, vector<int>& dist, int src){
        // min-heap
        priority_queue<PII, vector<PII>, greater<PII>> pq;

        dist[src] = 0;
        pq.push({dist[src], src});

        while(!pq.empty())
        {
            int curr = pq.top().second;
            pq.pop();

            for(auto [nei, wt]: graph[curr])
                if(dist[curr] + wt < dist[nei])
                {
                    dist[nei] = dist[curr] + wt;
                    pq.push({dist[nei], nei});
                }
        }
    }

public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<PII>> graph(n);

        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];
            graph[a].push_back({b, wt});
            graph[b].push_back({a, wt});
        }

        // min-dist of all nodes from node 0
        vector<int> dist1(n, INF);
        // min-dist of all nodes from node n-1
        vector<int> dist2(n, INF);

        // start dijkstra at node 0
        dijkstra(graph, dist1, 0);
        // start dijkstra at node n-1
        dijkstra(graph, dist2, n-1);

        vector<bool> ans;

        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];

            bool cond1 = dist1[a] != INF && dist2[b] != INF && dist1[a] + dist2[b] + wt == dist1[n-1];
            bool cond2 = dist1[b] != INF && dist2[a] != INF && dist1[b] + dist2[a] + wt == dist1[n-1];

            ans.push_back(cond1 || cond2);
        }
        
        return ans;
    }
};