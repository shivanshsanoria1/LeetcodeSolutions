#include <bits/stdc++.h> 

#define INF int(1e9)

int bellmonFord(int V, int E, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(V + 1, INF);
    dist[src] = 0;
    int relax = V - 1;
    while(relax--)
    {
        bool relaxDone = false;
        for(auto& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];
            if(dist[a] != INF && dist[a] + wt < dist[b])
                dist[b] = dist[a] + wt;
            relaxDone = true;
        }
        if(!relaxDone)
            break;
    }
    return dist[dest];
}

/*
# T.C.=O(V*E), S.C.=O(V)
# works with -ive edge weights
# can detect -ive weight cycle
# based on DP approach
*/