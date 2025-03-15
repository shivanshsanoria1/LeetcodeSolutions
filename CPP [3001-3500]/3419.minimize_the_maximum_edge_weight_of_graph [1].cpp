class Solution {
private:
    typedef pair<int, int> PII;

    void dfs(vector<vector<PII>>& graph, vector<bool>& visited, int curr){
        if(visited[curr])
            return;
        
        visited[curr] = true;

        for(auto [nei, wt]: graph[curr])
            dfs(graph, visited, nei);
    }

    // Prim's algo. for MST
    // returns the max edge wt. in the MST
    int minimumSpanningTree(vector<vector<PII>>& graph){
        int V = graph.size();

        vector<int> visited(V, false);
        // min-heap; {wt, curr, parent}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, -1});
        int sumMST = 0;
        int maxEdgeWt = 1;
        
        while(!pq.empty())
        {
            int wt = pq.top()[0];
            int curr = pq.top()[1];
            int parent = pq.top()[2];
            pq.pop();
            
            if(visited[curr])
                continue;
                
            visited[curr] = true;
            sumMST += wt;
            
            maxEdgeWt = max(maxEdgeWt, wt);
            
            for(auto [nei, wt]: graph[curr])
            {
                if(visited[nei])
                    continue;
                pq.push({wt, nei, curr});
            }
        }
        
        return maxEdgeWt;
    }

public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        // build the graph with inverted edges
        vector<vector<PII>> graph(n);
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            int wt = edge[2];

            graph[b].push_back({a, wt});
        }

        // check if all the nodes are reachable from node 0
        vector<bool> visited(n, false);
        dfs(graph, visited, 0);

        for(int i=0; i<n; i++)
            if(!visited[i])
                return -1;
            
        // at this point all the nodes are reachable from node 0

        return minimumSpanningTree(graph);
    }
};