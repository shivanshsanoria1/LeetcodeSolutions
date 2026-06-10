class Solution {
public:
    void dfs(vector<vector<int>>& graph, int i)
    {
        for(int j=0; j<graph.size(); j++)
        {
            if(graph[i][j] != 1) // not an unvisited edge
                continue;
            graph[i][j] = 2; // mark the edge from i -> j as visited
            graph[j][i] = 2; // mark the edge from j -> i as visited
            dfs(graph, j);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) { // DFS, T.C.=O(n^2), S.C.=O(1)
        int n = isConnected.size();
        int count = 0;
        for(int i=0; i<n; i++)
            if(isConnected[i][i] == 1) // unvisited row
            {
                isConnected[i][i] = 2; // mark the curr row as visited
                dfs(isConnected, i); // run dfs() for the curr row
                count++;
            }
        // [Not required] restore the orignal graph
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(isConnected[i][j] == 2)
                    isConnected[i][j] = 1;
        return count;
    }
};
/*
# 0: no edge, 1: unvisited edge, 2: visited edge
# graph[i][i] = 1 means row i is unvisited
# graph[i][i] = 2 means row i is visited
*/