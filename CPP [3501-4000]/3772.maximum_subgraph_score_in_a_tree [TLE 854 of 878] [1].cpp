class Solution {
private:
    int dfs(vector<vector<int>>& graph, vector<int>& good, int curr, int parent){
        int res = 0;
        for(int nei: graph[curr]){
            if(nei == parent)
                continue;

            int val = dfs(graph, good, nei, curr);
            if(val > 0)
                res += val;
        }

        return (good[curr] == 1 ? 1 : -1) + res;
    }

public:
    // T.C.=O(n^2), S.C.=O(n)
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<vector<int>> graph(n);
        for(vector<int>& edge: edges){
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> ans;
        for(int i=0; i<n; i++)
            ans.push_back(dfs(graph, good, i, -1));

        return ans;
    }
};