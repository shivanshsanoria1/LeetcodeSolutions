class Solution {
private:
    #define INF int(1e8)

public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V, INF);
        dist[src] = 0;
        // relax all the edges V times
        for(int r=1; r<=V; r++)
            for(auto edge: edges)
            {
                int a = edge[0];
                int b = edge[1];
                int wt = edge[2];
                if(dist[a] != INF && dist[a] + wt < dist[b])
                {
                    // relaxation still possible on the Vth iteration
                    if(r == V) 
                        return {-1};
                    dist[b] = dist[a] + wt;
                }
            }
        return dist;
    }
    
    /*
    # T.C.=O(V*E), S.C.=O(V)
    # works with -ive edge weights
    # can detect -ive weight cycle
    # based on DP approach
    */
};
