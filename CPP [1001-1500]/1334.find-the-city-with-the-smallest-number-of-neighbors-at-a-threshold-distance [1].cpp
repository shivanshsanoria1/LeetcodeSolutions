class Solution {
private:
    #define INF int(1e9)

public:
    // T.C.=O(n^3), S.C.=O(n^2)
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) { 
        vector<vector<int>> dist(n, vector<int>(n, INF));
        // build adjacency matrix
        for(vector<int>& edge: edges) 
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
        int ans = n;
        for(int i=n-1; i>=0; i--)
        {
            // num of cities at dist. <= threshold dist. from ith city
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
// dist[i][j]: min dist between cities i and j