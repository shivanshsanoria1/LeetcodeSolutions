class Solution {
public:
    void bfs(vector<vector<int>>& graph, int v)
    {
        int n = graph.size();
        queue<int> q;
        graph[v][v] = 2;
        q.push(v);
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            for(int j=0; j<n; j++)
            {
                if(graph[i][j] != 1) // not an unvisited edge
                    continue;
                graph[i][j] = 2; // mark the edge from i -> j as visited
                graph[j][i] = 2; // mark the edge from j -> i as visited
                q.push(j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) { // BFS, T.C.=O(n^2), S.C.=O(1)
        int n = isConnected.size();
        int count = 0;
        for(int i=0; i<n; i++)
            if(isConnected[i][i] == 1) // unvisited row
            {
                bfs(isConnected, i);
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