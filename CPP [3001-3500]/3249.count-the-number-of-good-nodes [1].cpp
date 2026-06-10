class Solution {
private:
    int dfs(vector<vector<int>>& graph, int curr, int parent, int& goodSubtrees){
        int subtreeSize = 1;
        unordered_set<int> s;

        for(int nei: graph[curr])
        {
            if(nei == parent)
                continue;
                
            int neiSubtreeSize = dfs(graph, nei, curr, goodSubtrees);
            subtreeSize += neiSubtreeSize;
            s.insert(neiSubtreeSize);
        }

        if(s.size() <= 1)
            goodSubtrees++;
        
        return subtreeSize;
    }

public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> graph(n);
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int goodSubtrees = 0;
        dfs(graph, 0, -1, goodSubtrees);
        return goodSubtrees;
    }
};