class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr) {
        if(visited[curr])
            return;
        visited[curr] = true;
        for(int nei: graph[curr])
            dfs(graph, visited, nei);
    }

public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        // graph has indexes and not values
        vector<vector<int>> graph(n);
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                if(gcd(nums[i], nums[j]) > 1)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }

        vector<bool> visited(n, false);
        dfs(graph, visited, 0);

        // some indexes are not reachable from index 0, ie,
        // graph has more than 1 component
        for(int i=0; i<n; i++)
            if(!visited[i])
                return false;
        // graph has exactly 1 component
        return true;
    }
};