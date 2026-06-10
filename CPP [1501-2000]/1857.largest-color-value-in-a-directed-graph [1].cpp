class Solution {
private:
    int dfs(vector<vector<int>>& graph, string& colors, vector<bool>& visited, vector<bool>& pathVisited, vector<vector<int>>& dp, int curr){
        // cycle found
        if(pathVisited[curr])
            return -1;
        // already visited node
        if(visited[curr])
            return 0;

        // mark the curr node as visited
        pathVisited[curr] = true;
        visited[curr] = true;

        int currColorIdx = colors[curr] - 'a';

        for(int nei: graph[curr])
        {
            int dfsVal = dfs(graph, colors, visited, pathVisited, dp, nei);
            
            // cycle found
            if(dfsVal == -1)
                return -1;
            
            // find the max of curr freq and nei freq
            // for each color
            for(int j=0; j<26; j++)
                dp[curr][j] = max(dp[curr][j], dp[nei][j]);
        }

        // add the curr node's color in dp
        dp[curr][currColorIdx]++;

        // remove the curr node from path visited
        pathVisited[curr] = false;

        return 0;
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.length();

        // build-graph
        vector<vector<int>> graph(n);
        for(auto& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            // self-edge forms a cycle
            if(a == b)
                return -1;
            graph[a].push_back(b);
        }

        vector<bool> visited(n, false); 
        vector<bool> pathVisited(n, false); 
        // dp fo size n*26 filled with 0's
        vector<vector<int>> dp(n, vector<int>(26, 0));

        for(int i=0; i<n; i++)
        {
            // skip the visited nodes
            if(visited[i])
                continue;

            int dfsVal = dfs(graph, colors, visited, pathVisited, dp, i);

            // cycle found
            if(dfsVal == -1)
                return -1;
        }

        int maxColor = 1;
        for(int i=0; i<n; i++)
            for(int j=0; j<26; j++)
                maxColor = max(maxColor, dp[i][j]);
               
        return maxColor;
    }
};
// dp[i][j]: max num of j color nodes in a path starting at ith node