class Solution {
private:
    // returns the number of vertices reachable from a source vertex
    int dfs(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int curr){
        if(visited.find(curr) != visited.end())
            return 0;

        visited.insert(curr);

        int count = 1;

        for(int nei: graph[curr])
            count += dfs(graph, visited, nei);

        return count;
    }

public:
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        // build graph
        unordered_map<int, vector<int>> graph;
        for(int i=0; i<n-1; i++) 
            for(int j=i+1; j<n; j++)
                if(__gcd(nums[i], nums[j]) > 1)
                {
                    graph[nums[i]].push_back(nums[j]);
                    graph[nums[j]].push_back(nums[i]);
                }

        unordered_set<int> visited;

        int maxCompSize = 0;

        for(auto it: graph)
        {
            int curr = it.first;
            // curr is unvisited
            if(visited.find(curr) == visited.end())
                maxCompSize = max(maxCompSize, dfs(graph, visited, curr));
        }

        return maxCompSize;
    }
};