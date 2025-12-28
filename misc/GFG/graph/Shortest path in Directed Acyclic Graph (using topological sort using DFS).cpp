class Solution {
private:
    #define INF INT_MAX
    typedef pair<int, int> PI; // {b, wt}

    void dfs(vector<vector<PI>>& graph, vector<bool>& visited, stack<int>& st, int curr){
        if(visited[curr])
            return;
        visited[curr] = true;
        for(auto it: graph[curr])
        {
            int nei = it.first;
            dfs(graph, visited, st, nei);
        }
        st.push(curr);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges){
        // code here
        vector<vector<PI>> graph(V);
        for(auto& edge: edges) // build graph
        {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];
            graph[a].push_back({b, wt});
        }
        // topological sort
        vector<bool> visited(V, false);
        stack<int> st;
        for(int i=0; i<V; i++)
            if(!visited[i])
                dfs(graph, visited, st, i);
        // relax all the outgoing edges connected to the curr vertex
        vector<int> dist(V, INF);
        dist[0] = 0;
        while(!st.empty())
        {
            int curr = st.top();
            st.pop();
            for(auto it: graph[curr])
            {
                int nei = it.first;
                int wt = it.second;
                if(dist[curr] != INF && dist[curr] + wt < dist[nei])
                    dist[nei] = dist[curr] + wt;
            }
        }
        // return -1 for the unreachable vertices
        for(int i=0; i<V; i++)
            if(dist[i] == INF)
                dist[i] = -1;
        return dist;
    }
    
    /*
    # topological sort (using DFS)
    # T.C.=O(V + E), S.C.=O(V)
    # no need to use Bellman-ford or Dijkstra's algo. as the graph is acyclic
    */
};
