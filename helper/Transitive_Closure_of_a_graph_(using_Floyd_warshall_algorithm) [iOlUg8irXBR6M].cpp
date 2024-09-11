#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

vector<vector<bool>> transitiveClosure(int V, vector<vector<int>>& edges){
    // V*V grid filled with false's
    vector<vector<bool>> reach(V, vector<bool>(V, false));
    
    // every vertex is reachable from itself
    for(int i=0; i<V; i++)
        reach[i][i] = true;
    
    // vertex 'b' is reachable from vertex 'a'
    for(vector<int>& edge: edges)
    {
        int a = edge[0];
        int b = edge[1];
        reach[a][b] = true;
    }
    
    for(int via=0; via<V; via++)
        for(int i=0; i<V; i++)
            for(int j=0; j<V; j++)
            {
                if(reach[i][j])
                    continue;
                reach[i][j] = reach[i][via] && reach[via][j];
            }
    
    return reach;
}

// --------------- END --------------- //

int main() {
    int V = 4; // vertices
    // directed edge: {a, b} means  a -> b
    vector<vector<int>> edges = { {0, 1}, {0, 3}, {1, 2}, {2, 3} };
    
    vector<vector<bool>> reach = transitiveClosure(V, edges);
    
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
            cout<<reach[i][j]<<" ";
        cout<<endl;
    }
    
    cout<<"-----------------"<<endl;

    return 0;
}

/* 
# T.C.=O(V^3)
# reach[i][j]: whether the vertex j is reachable from vertex i or not
  in other words, whether there exists a path from vertex i to vertex j
*/