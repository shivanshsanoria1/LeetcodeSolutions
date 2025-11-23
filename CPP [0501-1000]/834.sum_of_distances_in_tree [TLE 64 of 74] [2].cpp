class Solution {
private:
    int dfs(vector<vector<int>>& graph, int curr, int parent, int level){
        int sum = level;

        for(int nei: graph[curr])
            if(nei != parent)
                sum += dfs(graph, nei, curr, level + 1);
        
        return sum;
    }

public:
    // T.C.=O(n^2)
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // build graph
        vector<vector<int>> graph(n);
        for(vector<int>& edge: edges) 
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> ans(n, 0);

        for(int i=0; i<n; i++)
            ans[i] = dfs(graph, i, -1, 0);

        return ans;
    }
};
// T.C. = O(V*(V+E)) = O(n*(n + n-1)) = O(n^2)