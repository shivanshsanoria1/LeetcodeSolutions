class Solution {
private:
    // detect cycle in directed graph using dfs()
    bool isCyclic(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& pathVisited, int curr){
        visited[curr] = true;
        pathVisited[curr] = true;

        for(int nei: graph[curr])
            if(pathVisited[nei] || isCyclic(graph, visited, pathVisited, nei))
                return true;

        pathVisited[curr] = false;
        return false;
    }

    // Topo-sort
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& topoSort, int curr){
        if(visited[curr])
            return;
        
        visited[curr] = true;

        for(int nei: graph[curr])
            dfs(graph, visited, topoSort, nei);
        
        topoSort.push_back(curr);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        // build-graph
        vector<vector<int>> graph(n);
        for(vector<int>& pre: prerequisites)
        {
            int a = pre[0];
            int b = pre[1];
            graph[a].push_back(b); 
        }

        // check if the graph has cycle
        vector<bool> visited(n, false);
        vector<bool> pathVisited(n, false);
        
        for(int i=0; i<n; i++)
            if(!visited[i] && isCyclic(graph, visited, pathVisited, i))
                return {};

        // pathVisited is no longer needed
        pathVisited.clear();

        // reset 'visited'
        for(int i=0; i<n; i++)
            visited[i] = false;

        vector<int> topoSort;

        for(int i=0; i<n; i++)
            if(!visited[i])
                dfs(graph, visited, topoSort, i);

        return topoSort;
    }
};
/*
# A -> B indicates: 
  # A is dependent on B
  # B is a prerequisite of A
  # To complete A we need to complete B first
# for topo-sort using dfs(), the array is 
  reversed after all dfs() are completed
# here the ans is the reversed topo-sort 
  to get the least to most dependent nodes
# so in the end, 2 reversals mean 0 reversals are required
*/