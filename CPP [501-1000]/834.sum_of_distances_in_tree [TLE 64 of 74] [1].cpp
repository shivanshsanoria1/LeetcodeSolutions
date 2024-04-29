class Solution {
private:
    int bfs(vector<vector<int>>& graph, int src){
        int n=graph.size();
        vector<bool> visited(n, false);
        queue<int> q;

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

public:
    // T.C.=O(n^2)
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // build graph
        vector<vector<int>> graph(n);
        for(vector<int>& edge: edges) 
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> ans(n, 0);

        for(int i=0; i<n; i++)
            ans[i] = bfs(graph, i);

        return ans;
    }
};
// T.C. = O(V*(V+E)) = O(n*(n + n-1)) = O(n^2)