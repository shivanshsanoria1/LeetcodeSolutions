class Solution {
private:
    typedef pair<int, int> PII;
    #define MOD int(1e9 + 7)
    
    int dfs(vector<vector<PII>>& graph, vector<int>& ans, int curr){
        // answer already calcualted for curr node
        if(ans[curr] != -1)
            return ans[curr];

        int pro = 1;
        for(auto [nei, wt]: graph[curr])
        {
            // to prevent int overflow
            long long int val = ((long long int)wt * dfs(graph, ans, nei)) % MOD;
            pro = (pro * val) % MOD;
        }

        // store the calculated answer
        ans[curr] = pro;
        return pro;
    }
    
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1;
        vector<vector<PII>> graph(n);
        // build a graph with reversed edges
        for(vector<int>& conversion: conversions)
        {
            int a = conversion[0];
            int b = conversion[1];
            int wt = conversion[2];

            graph[b].push_back({a, wt});
        }

        vector<int> ans(n, -1);
        // 1 unit of type 0 is equal to 1 unit of type 0
        ans[0] = 1;
        // calculte the ans for nodes 1 to n-1
        for(int i=1; i<n; i++)
            ans[i] = dfs(graph, ans, i);

        return ans;
    }
};