class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<int>& visited, int curr){
        if(visited[curr] != 0)
            return;

        visited[curr] = 1;
        for(int nei: graph[curr])
            dfs(graph, visited, nei);
    }

public:
    // T.C.=O(n + (maxX + maxY)), S.C.=O(maxX + maxY)
    // maxX, maxY: max val of stone[0] and stone[1] respectively
    int removeStones(vector<vector<int>>& stones) {
        int maxX = 0, maxY = 0;
        for(vector<int>& stone: stones)
        {
            maxX = max(maxX, stone[0]);
            maxY = max(maxY, stone[1]);
        }

        vector<vector<int>> graph(maxX + 1 + maxY + 1);
        // initially all nodes are marked as empty
        vector<int> visited(maxX + 1 + maxY + 1, -1);
        for(vector<int>& stone: stones)
        {
            int a = stone[0];
            // offset the y coordinate by (maxX + 1)
            int b = maxX + 1 + stone[1];

            // connect the nodes a and b with an undirected edge
            graph[a].push_back(b);
            graph[b].push_back(a);

            // mark the nodes a and b as unvisited
            visited[a] = 0;
            visited[b] = 0;
        }

        // count components
        int components = 0;
        for(int i=0; i<visited.size(); i++)
            if(visited[i] == 0)
            {
                dfs(graph, visited, i);
                components++;
            }
        
        return stones.size() - components;
    }
};

/*
# using rows and cols as nodes of a graph
# size of graph must be ((maxX + 1) + (maxY + 1))
# row coordinate remains the same for a node but, 
  col coordinate is offset by (maxX + 1)
# visited[i] = 0: unvisited, 1: visited, -1: empty
*/