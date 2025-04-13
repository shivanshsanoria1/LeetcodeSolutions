class Solution {
private:
    string getHash(int a, int b){
        return to_string(min(a, b)) + "#" + to_string(max(a, b));
    }

    #define INF int(1e9)
    typedef pair<int, int> PII;

    // returns the shortest distance between src = 1 and dest node
    int dijkstra(vector<vector<int>>& graph, unordered_map<string, int>& edgeWts, int dest){
        int V = graph.size();
        int src = 1;
        
        // initially distance of reaching any node 
        // from source node is assumed to be infinity
        vector<int> dist(V, INF);
        // distance of reaching source node from itself is 0
        dist[src] = 0;
        
        // min-heap; {dist[i], i}
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({dist[src], src});
        
        while(!pq.empty())
        {
            int curr = pq.top().second;
            pq.pop();
            
            // relax the edge between curr and nei (if possible)
            for(int nei: graph[curr])
            {
                int wt = edgeWts[getHash(curr, nei)];
                if(dist[curr] != INF && dist[curr] + wt < dist[nei])
                {
                    dist[nei] = dist[curr] + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }
        
        return dist[dest];
    }

public:
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n+1);
        // edge hash -> wt
        unordered_map<string, int> edgeWts;
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];

            graph[a].push_back(b);
            graph[b].push_back(a);
            edgeWts[getHash(a, b)] = wt;
        }

        vector<int> ans;
        for(vector<int>& query: queries)
        {
            int type = query[0];

            if(type == 1)
            {
                int a = query[1];
                int b = query[2];
                int wt = query[3];
                edgeWts[getHash(a, b)] = wt;
            }
            else // type == 2
            {
                int dest = query[1];
                ans.push_back(dijkstra(graph, edgeWts, dest));
            }
        }

        return ans;
    }
};