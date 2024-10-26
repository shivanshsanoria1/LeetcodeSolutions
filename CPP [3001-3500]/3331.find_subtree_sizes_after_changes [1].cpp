class Solution {
private:
    void findNewParents(vector<vector<int>>& graph, int curr, int par, string& s, 
    vector<int>& parent, vector<int>& pathVisitedChars){
        // a node with same char-val as the curr node is present 
        // in the curr path, so it becomes the new parent
        if(pathVisitedChars[s[curr] - 'a'] != -1)
            parent[curr] = pathVisitedChars[s[curr] - 'a'];
        
        // save the prev node value, so it can be restored later
        int temp = pathVisitedChars[s[curr] - 'a'];
        // curr-node now has the most recent char-val in the curr path
        pathVisitedChars[s[curr] - 'a'] = curr;
        
        for(int nei: graph[curr])
            if(nei != par)
                findNewParents(graph, nei, curr, s, parent, pathVisitedChars);

        // remove the curr-node's char-val from the curr path
        pathVisitedChars[s[curr] - 'a'] = temp;
    }

    int findSize(vector<vector<int>>& graph, int curr, int par, 
    vector<int>& parent, vector<int>& ans){
        for(int nei: graph[curr])
            if(nei != par)
                ans[curr] += findSize(graph, nei, curr, parent, ans);

        return ans[curr];
    }

public:
    // T.C.=O(n), S.C.=O(n)
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        // Step 1: build a graph with original parents
        vector<vector<int>> graph(n);
        for(int i=1; i<n; i++)
        {
            graph[i].push_back(parent[i]);
            graph[parent[i]].push_back(i);
        }

        // Step 2: find the new possibly updated parents
        // keeps track of the most recent node with that char-val
        vector<int> pathVisitedChars(26, -1);
        findNewParents(graph, 0, -1, s, parent, pathVisitedChars);

        // Step 3: clear the old graph and 
        // build a new one with the updated parents
        graph.clear();
        graph.resize(n);
        for(int i=1; i<n; i++)
        {
            graph[i].push_back(parent[i]);
            graph[parent[i]].push_back(i);
        }
        
        // Step 4: find the subtree size for 
        // each node in the updated graph
        vector<int> ans(n, 1);
        findSize(graph, 0, -1, parent, ans);
        
        return ans;
    }
};