class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<unordered_set<int>>& reachable, int curr){
        // already visited node
        if(reachable[curr].find(curr) != reachable[curr].end())
            return;

        // mark the curr node as visited
        reachable[curr].insert(curr); 

        for(int nei: graph[curr]) 
        {
            dfs(graph, reachable, nei);
            // all the nodes reachable from 'nei' 
            // are also reachable from 'curr' 
            for(int r: reachable[nei])
                reachable[curr].insert(r);
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

        vector<unordered_set<int>> reachable(n);

        for(int i=0; i<n; i++)
            dfs(graph, reachable, i);

        vector<bool> ans;

        for(vector<int>& query: queries)
        {
            int a = query[0];
            int b = query[1];
            // a is prerequisite of b, ie, a <- b
            // starting at b, is it possible to reach a
            ans.push_back(reachable[b].find(a) != reachable[b].end());
        }

        return ans;
    }
};
/*
# A -> B indicates: 
  # A is dependent on B
  # B is a prerequisite of A
  # To complete A we need to complete B first

# reachable[i] indicates: 
  # all the nodes reachable from i
  # all the prerequisites of i

# reachable[i] can have i itself, since
  # i is always reachable from itself
  # i is a prerequisite of itself
  # reachable[i] having i itself is 
    used as a visited set here
*/