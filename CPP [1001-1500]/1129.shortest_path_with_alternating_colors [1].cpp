class Solution {
private:
    typedef pair<int, int> PI; // {vertex, edge color}

public:
    void bfs(vector<vector<PI>>& graph, vector<int>& ans, int src){
        int n=graph.size();
        queue<vector<int>> q; // {vertex, prev edge color, steps}
        // vector of size n*2; col0 for color Red, col1 for color Blue
        vector<vector<bool>> visited(n, vector(2, false)); 
        visited[src][0] = true, visited[src][1] = true;
        q.push({src, -1, 0});
        ans[src] = 0;
        while(!q.empty())
        {
            int curr = q.front()[0];
            int currColor = q.front()[1];
            int steps = q.front()[2];
            q.pop();
            if(ans[curr] == -1)
                ans[curr] = steps;
            for(auto [nei, neiColor]: graph[curr])
            {
                if(visited[nei][neiColor])
                    continue;
                if(currColor == neiColor)
                    continue;
                visited[nei][neiColor] = true;
                q.push({nei, neiColor, 1 + steps});
            }
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<PI>> graph(n);
        for(auto& edge: redEdges)
            graph[edge[0]].push_back({edge[1], 0});
        for(auto& edge: blueEdges)
            graph[edge[0]].push_back({edge[1], 1});

        vector<int> ans(n, -1);
        bfs(graph, ans, 0);
        return ans;
    }
};

// -1: invalid color, 0: Red, 1: Blue