class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr){
        if(visited[curr])
            return;

        visited[curr] = true;
        for(int nei: graph[curr])
            dfs(graph, visited, nei);
    }

public:
    // T.C.=O(n^2), S.C.=O(n^2)
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>> graph(n);
        for(int i=0; i<n; i++)
        {
            int x1 = stones[i][0], y1 = stones[i][1];
            for(int j=0; j<n; j++)
            {
                if(i == j)
                    continue;
                int x2 = stones[j][0], y2 = stones[j][1];
                // ith and jth stone are connected
                if(x1 == x2 || y1 == y2)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int components = 0;
        for(int i=0; i<n; i++)
            if(!visited[i])
            {
                dfs(graph, visited, i);
                components++;
            }
        
        return stones.size() - components;
    }
};

/*
# using index of stone as node of a graph
# for each component of size S we can remove (S-1) stones, 
  so that at the end only 1 stone remains in each component
# suppose there are 'c' components with the size of ith component being Si, then
  S1 + S2 + S3 + ... + Sc = n
# num of removalable stones is:
  (S1 - 1) + (S2 - 1) + (S3 - 1) + ... + (Sc - 1)
= (S1 + S2 + S3 + ... + Sz) - 1*c
= n - c
*/