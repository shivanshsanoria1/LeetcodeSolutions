class Solution {
private:
    // Topological sort using BFS (Kahn's algo.)
    // returns the number of vertices in topological sort starting at vertex 0
    int topoSort(int V, vector<vector<int>>& graph){
        // calculate indegree of each vertex
        vector<int> indegrees(V, 0);
        for(int i=0; i<V; i++)
            for(int nei: graph[i])
                indegrees[nei]++;
        // push the vertices with indegree 0 in queue
        queue<int> q;
        for(int i=0; i<V; i++)
            if(indegrees[i] == 0)
                q.push(i);
        
        int count = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            count++;
            // decrement the indegree of neighbours of curr
            // if their indegree becomes 0 push them in queue
            for(int nei: graph[curr])
            {
                indegrees[nei]--;
                if(indegrees[nei] == 0)
                    q.push(nei);
            }
        }
        return count;
    }
    
public:
    bool isPossible(int V, int E, vector<pair<int, int>>& prerequisites) {
        // Code here
        vector<vector<int>> graph(V);
        for(auto& pre: prerequisites) // build graph
        {
            int a = pre.first;
            int b = pre.second;
            graph[b].push_back(a);
        }
        return topoSort(V, graph) == V ? true : false;
    }
    //T.C.=O(V + E), S.C.=O(V + E)
};