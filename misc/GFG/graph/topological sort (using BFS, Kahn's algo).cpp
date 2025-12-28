class Solution
{
public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
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
        
        vector<int> ans;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            // decrement the indegree of neighbours of curr
            // if their indegree becomes 0 push them in queue
            for(int nei: adj[curr])
            {
                indegrees[nei]--;
                if(indegrees[nei] == 0)
                    q.push(nei);
            }
        }
        return ans;
	}
	
	/*
    # BFS, Kahn's algo.
    # T.C.=O(V+E), S.C.=O(V)
    # Topological sort works only for DAG (Directed Acyclic Graph)
    # indegree: num of incoming edges to a vertex
    */

};
