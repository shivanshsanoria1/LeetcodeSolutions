class Solution {
private:
    int dfs(vector<vector<int>>& graph, vector<int>& quiet, vector<int>& ans, int curr) {
        if(ans[curr] != -1)
            return ans[curr];

        ans[curr] = curr;
        for(int nei: graph[curr])
        {
            int loudestNei = dfs(graph, quiet, ans, nei);
            if(quiet[loudestNei] < quiet[ans[curr]])
                ans[curr] = loudestNei;
        }

        return ans[curr];
    }

public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> graph(n);
        for(int i=0; i<richer.size(); i++)
            graph[richer[i][1]].push_back(richer[i][0]);
        
        vector<int> ans(n, -1);
        // Multi-Source DFS
        for(int i=0; i<n; i++)
            if(ans[i] == -1)
                dfs(graph, quiet, ans, i);
        return ans;
    }
};
// A <- B : A is richer than B