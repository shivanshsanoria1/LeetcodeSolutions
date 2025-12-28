class Solution
{
private:
    // Topological sort using BFS (Kahn's algo.)
    void topoSort(int V, vector<vector<int>>& graph, vector<int>& topo){
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
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            topo.push_back(curr);
            // decrement the indegree of neighbours of curr
            // if their indegree becomes 0 push them in queue
            for(int nei: graph[curr])
            {
                indegrees[nei]--;
                if(indegrees[nei] == 0)
                    q.push(nei);
            }
        }
    }
    
public:
    vector<int> findOrder(int V, int E, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<vector<int>> graph(V);
        for(auto& pre: prerequisites) // build graph
        {
            int a = pre[0];
            int b = pre[1];
            graph[b].push_back(a);
        }
        
        vector<int> topo;
        topoSort(V, graph, topo);
        
        if(topo.size() < V) // impossible to finish all tasks
            return {};
        return topo;
    }
    //T.C.=O(V + E), S.C.=O(V + E)
};
