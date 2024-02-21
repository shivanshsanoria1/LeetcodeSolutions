class Solution {
private:
    #define INF int(1e9)

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) { // T.C.=O(n^3), S.C.=O(n^2)
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for(auto& edge: edges) // build adjacency matrix
        {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];
            dist[a][b] = wt;
            dist[b][a] = wt;
        }

        // Floyd-Warshall algo.
        for(int via=0; via<n; via++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                {
                    if(i == j)
                        dist[i][j] = 0;
                    else
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }

        int minReachableCities = n;
        int ans = n-1;
        for(int i=n-1; i>=0; i--)
        {
            int reachableCities = 0;
            for(int j=0; j<n; j++)
                if(i != j && dist[i][j] <= distanceThreshold)
                    reachableCities++;
            if(reachableCities < minReachableCities)
            {
                minReachableCities = reachableCities;
                ans = i;
            }
        }
        return ans;
    }
};