class Solution {
public:
    // returns the num of vertices reachable from a source vertex
    int bfs(vector<vector<int>>& graph, vector<bool>& visited, int src){
        queue<int> q;
        visited[src] = true;
        q.push(src);
        int count = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            count++;
            for(int nei: graph[curr])
            {
                // skip the visited neighbours of curr
                if(visited[nei]) 
                    continue;
                visited[nei] = true;
                q.push(nei);
            }
        }
        return count;
    }

    long long countPairs(int n, vector<vector<int>>& edges) { // BFS
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
                long long int groupSize = bfs(graph, visited, i);
                ans += groupSize * (n - groupSize);
            }
        return ans / 2;
    }
};