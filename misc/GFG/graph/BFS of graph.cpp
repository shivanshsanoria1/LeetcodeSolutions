class Solution {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        vector<bool> visited(V, false);
        visited[0] = true;
        q.push(0);
        vector<int> ans;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(int nei: adj[curr])
            {
                if(visited[nei]) // skip the visited neighbours
                    continue;
                visited[nei] = true;
                q.push(nei);
            }
        }
        return ans;
    }
    
    // T.C.=O(V + E), S.C.=O(V)
};
