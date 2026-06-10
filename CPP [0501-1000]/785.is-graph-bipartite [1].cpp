class Solution {
private:
    bool bfs(vector<vector<int>>& graph, vector<int>& color, int src){
        queue<int> q;

        // source vertex is marked black color
        color[src] = 0; 
        q.push(src);

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                int curr = q.front();
                q.pop();

                int currColor = color[curr];

                for(int nei: graph[curr])
                {
                    // same colored adjacent vertices
                    if(color[nei] == currColor) 
                        return false;
                    // already colored vertex
                    if(color[nei] != -1) 
                        continue;
                    // fill opposite color to curr color
                    color[nei] = !currColor; 
                    q.push(nei);
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n, -1);

        for(int i=0; i<n; i++)
            // run bfs() only for uncolored vertices
            if(color[i] == -1 && !bfs(graph, color, i)) 
                return false;

        return true;
    }
};
/*
# -1: no color, 0: black, 1: red
# Bipartite Graph can be thought of as a graph in which every node be colored with just 2 colors,
such that no 2 adjacent nodes have the same color.
# A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that 
every edge in the graph connects a node in set A and a node in set B.
*/