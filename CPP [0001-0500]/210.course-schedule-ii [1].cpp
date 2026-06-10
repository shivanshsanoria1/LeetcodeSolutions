class Solution {
private:
    // Kahn's algo.
    void bfs(vector<vector<int>>& graph, vector<int>& indegree, vector<int>& topoSort){
        int n=indegree.size();
        queue<int> q;

        for(int i=0; i<n; i++)
            if(indegree[i] == 0)
                q.push(i);

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            topoSort.push_back(curr);

            for(int nei: graph[curr])
            {
                indegree[nei]--;
                if(indegree[nei] == 0)
                    q.push(nei);
            }
        }
        
        // topo-sort does not have all the nodes,
        // ie, there is a cycle in graph
        if(topoSort.size() != n)
            topoSort.clear();
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        // build-graph and compute the indegree of each node
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for(vector<int>& pre: prerequisites)
        {
            int a = pre[0];
            int b = pre[1];
            graph[a].push_back(b); 
            indegree[b]++; 
        }

        vector<int> topoSort;

        bfs(graph, indegree, topoSort);

        reverse(topoSort.begin(), topoSort.end());

        return topoSort;
    }
};
/*
# A -> B indicates: 
  # A is dependent on B
  # B is a prerequisite of A
  # To complete A we need to complete B first
# revese the topoSort before returning as here 
  the ans must be from least to most dependent
*/