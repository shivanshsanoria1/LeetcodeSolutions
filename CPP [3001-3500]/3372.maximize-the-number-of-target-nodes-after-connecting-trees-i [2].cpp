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
    int dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr, int k){
        if(k == -1 || visited[curr])
            return 0;
            
        visited[curr] = true;

        int count = 1;
        for(int nei: graph[curr])
            count += dfs(graph, visited, nei, k-1);

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
        {
            vector<bool> visited(n, false);
            ans1.push_back(dfs(graph1, visited, i, k));
        }

        int m = edges2.size() + 1;
        vector<int> ans2;
        for(int i=0; i<m; i++)
        {
            vector<bool> visited(m, false);
            ans2.push_back(dfs(graph2, visited, i, k-1));
        }

        int maxCount = *max_element(ans2.begin(), ans2.end());
        for(int i=0; i<n; i++)
            ans1[i] += maxCount;
        
        return ans1;
    }
};