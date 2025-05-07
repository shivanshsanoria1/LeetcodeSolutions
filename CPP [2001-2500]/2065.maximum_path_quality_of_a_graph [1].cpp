class Solution {
private:
    typedef pair<int, int> PII;

    int maxVal = 0;

    void dfs(vector<vector<PII>>& graph, vector<int>& values, vector<int>& visited, int maxTime, int currNode, int currTime, int currVal){
        if(currTime > maxTime)
            return;

        // increment the num of times curr node is visited
        // include the curr node's value if its visited for the 1st time
        if(visited[currNode]++ == 0)
            currVal += values[currNode];
        
        // reached the node 0 again
        if(currNode == 0)
            maxVal = max(maxVal, currVal);
        
        for(auto [nei, time]: graph[currNode])
            dfs(graph, values, visited, maxTime, nei, currTime + time, currVal);

        // decrement the num of times curr node is visited
        // exclude the curr node's value if it becomes unvisited
        if(--visited[currNode] == 0)
            currVal -= values[currNode];
    }

public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<PII>> graph(n);
        for(vector<int>& edge: edges)
        {
            int a = edge[0], b = edge[1];
            int t = edge[2];

            graph[a].push_back({b, t});
            graph[b].push_back({a, t});
        }

        // visited[i]: num of times the ith node is visited
        vector<int> visited(n, 0);
        dfs(graph, values, visited, maxTime, 0, 0, 0);

        return maxVal;
    }
};