class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<vector<bool>>& grid, int curr){
        // already visited node
        if(grid[curr][curr]) 
            return;

        // mark the curr node as visited
        grid[curr][curr] = true; 

        for(int nei: graph[curr]) 
        {
            dfs(graph, grid, nei);
            // all the nodes reachable from 'nei' 
            // are also reachable from 'curr' 
            for(int j=0; j<grid[0].size(); j++)
                if(grid[nei][j])
                    grid[curr][j] = true;
        }
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        // build-graph
        vector<vector<int>> graph(n);
        for(vector<int>& pre: prerequisites)
        {
            int a = pre[0];
            int b = pre[1];
            graph[b].push_back(a);
        }

        // n*n grid filled with false's
        vector<vector<bool>> grid(n, vector<bool>(n, false));

        for(int i=0; i<n; i++)
            dfs(graph, grid, i);

        vector<bool> ans;

        for(vector<int>& query: queries)
        {
            int a = query[0];
            int b = query[1];
            // a is prerequisite of b, ie, a <- b
            // starting at b, is it possible to reach a
            ans.push_back(grid[b][a]);
        }

        return ans;
    }
};
/*
# A -> B indicates: 
  # A is dependent on B
  # B is a prerequisite of A
  # To complete A we need to complete B first

# grid[i][j] indicates:
  # j is a prerequisite of i, ie, i -> j
  # j is reachable from i in the graph

# diagonal cells in grid, ie, grid[i][i] 
  are used as visited set for vertex i
*/