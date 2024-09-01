class Solution {
private:
    #define INF int(2e9)
    typedef pair<int, int> PII;

    int dijkstra(vector<vector<PII>>& graph, int src, int dest){
        int n = graph.size();

        vector<int> dist(n, INF);
        dist[src] = 0;
        
        // min-heap; {dist[i], i}
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({dist[src], src});
        
        while(!pq.empty())
        {
            int curr = pq.top().second;
            pq.pop();
            
            for(auto [nei, wt]: graph[curr])
                if(dist[curr] != INF && dist[curr] + wt < dist[nei])
                {
                    dist[nei] = dist[curr] + wt;
                    pq.push({dist[nei], nei});
                }
        }
        
        return dist[dest];
    }

    void replaceNegEdgeWithInf(vector<vector<int>>& edges){
        for(vector<int>& edge: edges)
            if(edge[2] == -1)
                edge[2] = INF;
    }

public:
    // T.C.=O(E*(V+E)*log(V)), S.C.=O(V + E)
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        int src = source;
        int dest = destination;

        // build graph while ignoring the '-1' edges
        vector<vector<PII>> graph(n);
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];

            // skip the '-1' edge
            if(wt == -1)
                continue;
            
            graph[a].push_back({b, wt});
            graph[b].push_back({a, wt});
        }

        // initial min-dist between 'src' and 'dest'
        // while ignoring the '-1' edges
        int initialMinDist = dijkstra(graph, src, dest);
        
        // not possible to make the min-dist between 
        // 'src' and 'dest' equal to 'target'
        if(initialMinDist < target)
            return {};

        // min-dist between 'src' and 'dest' is already equal to 'target'
        // so replace each '-1' edge with INF so they don't interfere
        // with the initially found min-dist
        if(initialMinDist == target)
        {
            replaceNegEdgeWithInf(edges);
            return edges;
        }

        int minDistEqualsTarget = false;
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];

            // skip the +ive edge
            if(wt != -1)
                continue;

            // replace the '-1' edge with 1 and add it to graph
            edge[2] = 1;
            graph[a].push_back({b, 1});
            graph[b].push_back({a, 1});

            // run dijkstra() to find the newly found min-dist
            int minDist = dijkstra(graph, src, dest);

            // changing the curr edge wt. from -1 to 1 has 
            // reduced the min-dist to <= 'target'
            if(minDist <= target)
            {
                // add (target - minDist) wt. to curr edge wt.
                // to make the min-dist equal to 'target'
                edge[2] += target - minDist;
                // min-dist is now equal to 'target'
                minDistEqualsTarget = true;
                // replace each remaining '-1' edge with INF
                replaceNegEdgeWithInf(edges);
                break;
            }
        }

        // min-dist cannot be made equal to 'target'
        if(!minDistEqualsTarget)
            return {};

        return edges;
    }
};