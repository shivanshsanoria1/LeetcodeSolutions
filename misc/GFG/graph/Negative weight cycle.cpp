class Solution {
private:
    #define INF int(1e9)
    
public:
	int isNegativeWeightCycle(int V, vector<vector<int>>edges){
	    // Code here
	    vector<int> dist(V, INF);
	    dist[1] = 0;
        // relax all the edges V times
        for(int r=1; r<=V; r++)
            for(auto edge: edges)
            {
                int a = edge[0];
                int b = edge[1];
                int wt = edge[2];
                if(dist[a] != INF && dist[a] + wt < dist[b])
                {
                    // relaxation still possible on the Vth iteration, ie, 
                    if(r == V) // -ive weight cycle found
                        return 1;
                    dist[b] = dist[a] + wt;
                }
            }
        return 0;
	}
	/*
	# Bellman-Ford algo.
	# T.C.=O(V*E), S.C.=O(V)
	*/
};
