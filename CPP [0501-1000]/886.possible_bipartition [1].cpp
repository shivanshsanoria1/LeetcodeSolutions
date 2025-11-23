class Solution {
public:
    bool bfs(vector<vector<int>>& graph, vector<int>& color, int v)
    {
        queue<int> q;
        color[v] = 0; // vertex v is marked black color
        q.push(v);
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int curr = q.front();
                q.pop();
                int currColor = color[curr];
                for(int ver: graph[curr])
                {
                    if(color[ver] == -1) // uncolored vertex
                    {
                        color[ver] = !currColor; // fill opposite color to curr color
                        q.push(ver);
                    }
                    else if(color[ver] == currColor) // same colored adjacent vertices
                        return false;
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        for(auto edge: dislikes) // build the graph
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<int> color(n+1, -1);
        for(int i=1; i<=n; i++)
            if(color[i] == -1) // run bfs() only for uncolored vertices
                if(bfs(graph, color, i) == false)
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
# similar to Leetcode-785
# the dislikes here are bidirectional so- a dislikes b means b also dislikes a
*/