class Solution {
public:
    // returns the number of vertices reachable from a source vertex
    int dfs(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int curr){
        if(visited.find(curr) != visited.end()) // curr is visited
            return 0;
        visited.insert(curr);
        int count = 1;
        for(int nei: graph[curr])
            count += dfs(graph, visited, nei);
        return count;
    }

    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, vector<int>> graph;
        for(int i=0; i<n-1; i++) // build graph
            for(int j=i+1; j<n; j++)
                if(__gcd(nums[i], nums[j]) > 1)
                {
                    graph[nums[i]].push_back(nums[j]);
                    graph[nums[j]].push_back(nums[i]);
                }
        unordered_set<int> visited;
        int ans = 0;
        for(auto it: graph)
        {
            int curr = it.first;
            if(visited.find(curr) == visited.end()) // curr is unvisited
                ans = max(ans, dfs(graph, visited, curr));
        }
        return ans;
    }
};