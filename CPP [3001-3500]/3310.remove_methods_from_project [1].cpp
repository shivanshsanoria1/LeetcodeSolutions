class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr){
        if(visited[curr])
            return;
        
        visited[curr] = true;

        for(int nei: graph[curr])
            dfs(graph, visited, nei);
    }

public:
    // T.C.=O(V + E), S.C.=O(V + E)
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for(vector<int>& invocation: invocations)
        {
            int a = invocation[0];
            int b = invocation[1];
            
            graph[a].push_back(b);
        }

        vector<bool> visited(n, false);
        dfs(graph, visited, k);

        for(vector<int>& invocation: invocations)
        {
            int a = invocation[0];
            int b = invocation[1];
            
            // edge from unvisited to visited method means an
            // non-suspicious method invokes a suspicious method
            // thus, no method can be removed
            if(!visited[a] && visited[b])
            {
                vector<int> ans;
                for(int i=0; i<n; i++)
                    ans.push_back(i);

                return ans;
            }
        }

        // visited methods must be removed, ie, 
        // only include the unvisited methods
        vector<int> ans;
        for(int i=0; i<n; i++)
            if(!visited[i])
                ans.push_back(i);
        
        return ans;
    }
};