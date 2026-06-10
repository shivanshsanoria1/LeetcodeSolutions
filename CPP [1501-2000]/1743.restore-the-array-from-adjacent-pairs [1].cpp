class Solution {
private:
    void dfs(unordered_map<int, vector<int>>& graph, vector<int>& ans, int prev, int curr){
        ans.push_back(curr);
        for(auto nei: graph[curr])
            if(nei != prev)
                dfs(graph, ans, curr, nei);
    }

public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        for(auto& pair: adjacentPairs) // build-graph
        {
            int a = pair[0], b = pair[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int start = INT_MIN;
        for(auto it: graph) // find the starting vertex
            if(it.second.size() == 1)
            {
                start = it.first;
                break;
            }

        vector<int> ans;
        dfs(graph, ans, INT_MIN, start);
        return ans;
    }
};