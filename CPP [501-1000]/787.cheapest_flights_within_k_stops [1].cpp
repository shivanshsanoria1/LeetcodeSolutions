class Solution {
private:
    #define INF INT_MAX

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // initially it takes infinite cost to reach any vertex from source
        vector<int> costs(n, INF); 
        // 0 cost to reach source from source
        costs[src] = 0; 
        // create a copy of costs vector
        vector<int> tempCosts(costs.begin(), costs.end());
        // (k+1) relaxations are required
        k++;
        while(k--)
        {
            for(auto& flight: flights)
            {
                int a = flight[0];
                int b = flight[1];
                int cost = flight[2];
                // relax the edge a -> b
                if(costs[a] != INF && costs[a] + cost < tempCosts[b])
                    tempCosts[b] = costs[a] + cost;
            }
            // copy the temp vector to the original costs vector
            for(int i=0; i<n; i++)
                costs[i] = tempCosts[i];
        }
        return costs[dst] == INF ? -1 : costs[dst];
    }
};
/*
# Bellman-Ford algo.
# T.C.=O((V+E)*K), S.C.=O(V)
# Relax all the edges for (k+1) times
# costs[dst] == INF means destination is unreachable from source with atmost k stops
*/