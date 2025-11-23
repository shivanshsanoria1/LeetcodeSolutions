class Solution {
private:
    #define INF INT_MAX
    typedef pair<int, int> PI;

public:
    int bfs(vector<vector<PI>>& graph, int n, int src, int dst, int k)
    {
        vector<int> costs(n, INF);
        costs[src] = 0;
        // create a copy of costs vector
        vector<int> tempCosts(costs.begin(), costs.end());
        queue<PI> q;
        q.push({src, 0});
        int level = 0;
        while(!q.empty())
        {
            if(level > k)
                break;
            int size = q.size();
            while(size--)
            {
                int a = q.front().first;
                q.pop();
                for(auto& nei: graph[a])
                {
                    int b = nei.first;
                    int cost = nei.second;
                    // relax the edge a -> b, edge wt = 'cost'
                    if(costs[a] != INF && costs[a] + cost < tempCosts[b])
                    {
                        tempCosts[b] = costs[a] + cost;
                        q.push(nei);
                    }
                }
            }
            level++;
            // copy the temp vector to the original costs vector
            for(int i=0; i<n; i++)
                costs[i] = tempCosts[i];
        }
        // costs[dst] == INF means destination is unreachable from source with atmost k stops
        return costs[dst] == INF ? -1 : costs[dst];
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) { // BFS
        vector<vector<PI>> graph(n);
        for(auto& flight: flights) // build graph
        {
            int a = flight[0];
            int b = flight[1];
            int cost = flight[2];
            graph[a].push_back({b, cost}); // a -> b, edge wt = cost
        }

        return bfs(graph, n, src, dst, k);
    }
};