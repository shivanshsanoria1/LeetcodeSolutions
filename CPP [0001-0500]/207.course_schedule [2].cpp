class Solution {
private:
    // Kahn's algo.
    // returns true if the topo-sort does not contain all the nodes
    // ie, if the graph has a cycle
    bool isCyclic(vector<vector<int>>& graph, vector<int>& indegree){
        int n=indegree.size();
        queue<int> q;

        for(int i=0; i<n; i++)
            if(indegree[i] == 0)
                q.push(i);
        
        int topoSortCount = 0;
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            topoSortCount++;

            for(int nei: graph[curr])
            {
                indegree[nei]--;
                if(indegree[nei] == 0)
                    q.push(nei);
            }
        }

        return topoSortCount != n;
    }

public:
    // T.C.=O(n + p)
    // n: numCourses, p: size of prerequisites[]
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        return !isCyclic(graph, indegree);
    }
};
/*
# A -> B indicates: 
  # A is dependent on B
  # B is a prerequisite of A
  # To complete A we need to complete B first
# core-idea: just find if the graph has a cycle or not
*/