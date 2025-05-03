#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

// returns true if no neighbour of curr is of color 'c'
bool canBeColored(vector<vector<int>>& graph, vector<int>& colors, int curr, int c){
    for(int nei: graph[curr])
        if(colors[nei] == c)
            return false;
    
    return true;
}

bool dfs(vector<vector<int>>& graph, vector<int>& colors, int m, int curr){
    int V = graph.size();
    // all the vertices are now colored
    if(curr == V)
        return true;
    
    for(int c=0; c<m; c++)
    {
        if(!canBeColored(graph, colors, curr, c))
            continue;
        
        // color the curr vertex with color 'c'
        // before recursively checking for next vertices
        colors[curr] = c;
        
        if(dfs(graph, colors, m, curr + 1))
            return true;
        
        // remove the color of curr vertex
        colors[curr] = -1;
    }
    
    return false;
}

// --------------- END --------------- //

int main() {
    int V = 4; // vertices
    int m = 3; // colors
    // undirected edges
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}};
    
    vector<vector<int>> graph(V);
    for(vector<int>& edge: edges)
    {
        int a = edge[0], b = edge[1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<int> colors(V, -1);
    
    if(dfs(graph, colors, m, 0))
    {
        cout<<"Graph can be colored with the m="<<m<<" colors"<<endl;
        cout<<"Vertex -> Color"<<endl;
        for(int i=0; i<V; i++)
            cout<<i<<" -> "<<colors[i]<<endl;
    }
    else
        cout<<"Graph cannot be colored with atmost m="<<m<<" colors"<<endl;
    
    cout<<endl<<"------------------"<<endl;

    return 0;
}

/*
# check if an undirected graph can be colored with atmost m colors
  such that no two adjacent vertices have the same color
*/