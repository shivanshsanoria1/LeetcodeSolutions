class Solution {
public:
    // returns the num of vertices reachable from a source vertex
    int dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr){
        if(visited[curr]) // curr vertex already visited
            return 0;
        visited[curr] = true; // mark the curr vertex as visited
        int count = 1;
        for(int nei: graph[curr])
            count += dfs(graph, visited, nei);
        return count;
    }

    long long countPairs(int n, vector<vector<int>>& edges) { // DFS
        vector<vector<int>> graph(n);
        for(auto edge: edges) // build graph
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        long long int ans = 0;
        for(int i=0; i<n; i++)
            if(!visited[i])
            {
                long long int groupSize = dfs(graph, visited, i);
                ans += groupSize * (n - groupSize);
            }
        return ans / 2;
    }
};