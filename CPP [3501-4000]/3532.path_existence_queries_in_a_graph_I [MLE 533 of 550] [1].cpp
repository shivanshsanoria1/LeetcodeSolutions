class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<int>& compIds, int compId, int curr){
        if(compIds[curr] != -1)
            return;
        
        compIds[curr] = compId;

        for(int nei: graph[curr])
            dfs(graph, compIds, compId, nei);
    }

public:
    // T.C.=O(n^2 + q), S.C.=O(n^2)
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for(int i=0; i<n; i++)
            for(int j=i+1; j < n && nums[j] <= nums[i] + maxDiff; j++)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }

        vector<int> compIds(n, -1);
        int compId = 0;
        for(int i=0; i<n; i++)
            if(compIds[i] == -1)
            {
                dfs(graph, compIds, compId, i);
                compId++;
            }

        vector<bool> ans;
        for(vector<int>& query: queries)
        {
            int a = query[0], b = query[1];
            ans.push_back(compIds[a] == compIds[b]);
        }

        return ans;
    }
};