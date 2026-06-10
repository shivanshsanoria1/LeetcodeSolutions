class Solution {
private:
    vector<vector<int>> buildGraph(vector<vector<int>>& edges){
        vector<vector<int>> graph(edges.size() + 1);

        for(vector<int>& edge: edges)
        {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        return graph;
    }

    // returns the num of nodes which are atmost k edges 
    // away from source node
    int bfs(vector<vector<int>>& graph, int src, int k){
        int n = graph.size();
        vector<bool> visited(n, false);
        queue<int> q;
        visited[src] = true;
        q.push(src);
        int level = 0;
        int count = 0;

        while(!q.empty())
        {
            if(level++ == k+1)
                break;

            int size = q.size();
            while(size--)
            {
                int curr = q.front();
                q.pop();
                count++;

                for(int nei: graph[curr])
                {
                    if(visited[nei])
                        continue;

                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }

        return count;
    }

public:
    // T.C.=O(n^2 + m^2), S.C.=O(n + m)
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<vector<int>> graph1 = buildGraph(edges1);
        vector<vector<int>> graph2 = buildGraph(edges2);

        int n = edges1.size() + 1;
        vector<int> ans1;
        for(int i=0; i<n; i++)
            ans1.push_back(bfs(graph1, i, k));

        int m = edges2.size() + 1;
        vector<int> ans2;
        for(int i=0; i<m; i++)
            ans2.push_back(bfs(graph2, i, k-1));

        int maxCount = *max_element(ans2.begin(), ans2.end());
        for(int i=0; i<n; i++)
            ans1[i] += maxCount;
        
        return ans1;
    }
};