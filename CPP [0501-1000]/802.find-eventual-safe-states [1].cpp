class Solution {
public:
    bool isCyclic(vector<vector<int>>& graph, vector<int>& status, vector<bool>& inCycle, int curr){
        // trying to process an already processing vertex, ie, cycle found
        if(status[curr] == 2) 
            return true;
        // mark the curr vertex as processing
        status[curr] = 2; 
        for(int nei: graph[curr])
            // check for all un-processed nodes adjacent to curr node for a cycle
            if(status[nei] != 1 && isCyclic(graph, status, inCycle, nei)) 
            {
                inCycle[curr] = true; // curr vertex is in a cycle
                return true;
            }
        status[curr] = 1; // mark the curr vertex as processed
        return false; // no cycle found
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        // to store the status of each vertex (0: unvisited, 1: processed, 2: processing)
        vector<int> status(n, 0);
        // to store the vertices present in a cycle
        vector<bool> inCycle(n, false);

        for(int i=0; i<n; i++)
            if(status[i] == 0)
                isCyclic(graph, status, inCycle, i);

        vector<int> ans;
        for(int i=0; i<n; i++)
            if(!inCycle[i]) // vertex not present in cycle
                ans.push_back(i);
        return ans;
    }
};
// 0: unvisited, 1: processed, 2: processing
// just find the vertices not present in a cycle