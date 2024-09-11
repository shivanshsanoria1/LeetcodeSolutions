#include <bits/stdc++.h>
using namespace std;

// --------------- START --------------- //

void dfs1(vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st, int curr){
    if(visited[curr])
        return;
    
    visited[curr] = true;
    for(int nei: graph[curr])
        dfs1(graph, visited, st, nei);
    
    // push the curr vertex in stack before returning
    st.push(curr);
}

void dfs2(vector<vector<int>>& graphT, vector<bool>& visited, int curr){
    if(visited[curr])
        return;
    
    visited[curr] = true;
    for(int nei: graphT[curr])
        dfs2(graphT, visited, nei);
}

int kosarajuSCC(int V, vector<vector<int>>& edges){
    // build the graph
    vector<vector<int>> graph(V);
    for(vector<int>& edge: edges)
    {
        int a = edge[0];
        int b = edge[1];
        
        graph[a].push_back(b);
    }
    
    // run dfs1() for all the vertices
    vector<bool> visited(V, false);
    stack<int> st;
    for(int i=0; i<V; i++)
        dfs1(graph, visited, st, i);
    
    // reset the visited[]
    for(int i=0; i<V; i++)
        visited[i] = false;
    
    // clear the graph and resize it for V vertices
    graph.clear();
    graph.resize(V);
    
    // build a Transpose graph, ie, graph with reversed edges, 
    // ie, replace each edge a -> b with a <- b
    for(vector<int>& edge: edges)
    {
        int a = edge[0];
        int b = edge[1];
        
        graph[b].push_back(a);
    }
    
    // run dfs2() for each unvisited vertex from stack
    int SCC_count = 0;
    while(!st.empty())
    {
        int curr = st.top();
        st.pop();
        
        if(visited[curr])
            continue;
            
        dfs2(graph, visited, curr);
        SCC_count++;
    }

    return SCC_count;
}

// --------------- END --------------- //

int main() {
    int V = 5; // vertices
    // directed edges, {a, b} means a -> b
    vector<vector<int>> edges = {{0, 2}, {0, 3}, {1, 0}, {2, 1}, {3, 4}};
    
    int SCC_count = kosarajuSCC(V, edges);
    cout<<"Strongly Connected Component (SCC) count = "<<SCC_count<<endl;
    
    cout<<endl<<"------------------"<<endl;
    
    
    return 0;
}