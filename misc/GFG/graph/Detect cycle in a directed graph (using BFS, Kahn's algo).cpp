class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // calculate indegree of each vertex
        vector<int> indegrees(V, 0);
        for(int i=0; i<V; i++)
            for(int nei: adj[i])
                indegrees[nei]++;
        // push the vertices with indegree 0 in queue
        queue<int> q;
        for(int i=0; i<V; i++)
            if(indegrees[i] == 0)
                q.push(i);
                
        // keeps track of number of vertices in topological sort
        int topoCount = 0; 
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            topoCount++;
            // decrement the indegree of neighbours of curr
            // if their indegree becomes 0 push them in queue
            for(int nei: adj[curr])
            {
                indegrees[nei]--;
                if(indegrees[nei] == 0)
                    q.push(nei);
            }
        }
        // if the topological sort has all the V vertices then graph is acyclic, 
        // otherwise it is cyclic
        return topoCount == V ? false : true;
    }
    
    /*
    # BFS, Kahn's algo.
    # T.C.=O(V+E), S.C.=O(V)
    # Topological sort works only for DAG (Directed Acyclic Graph)
    # indegree: num of incoming edges to a vertex
    */
};
