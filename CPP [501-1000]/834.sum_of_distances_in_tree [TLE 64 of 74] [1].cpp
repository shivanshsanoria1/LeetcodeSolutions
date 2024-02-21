class Solution {
public:
    int bfs(vector<vector<int>>& graph, int src){
        int n=graph.size();
        queue<int> q;
        vector<bool> visited(n, false);
        visited[src] = true;
        q.push(src);
        int level = 0;
        int levelSum = 0;
        while(!q.empty())
        {
            int size = q.size();
            levelSum += level * size;
            while(size--)
            {
                int curr = q.front();
                q.pop();
                for(int nei: graph[curr])
                {
                    if(visited[nei])
                        continue;
                    visited[nei] = true;
                    q.push(nei);
                }
            }
            level++;
        }
        return levelSum;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto& edge: edges) // build graph
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++)
            ans[i] = bfs(graph, i);
        return ans;
    }
};