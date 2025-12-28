class Solution
{
private:
    int bfs(int V, vector<int> graph[], int dest){
        queue<int> q;
        vector<bool> visited(V, false);
        visited[0] = true;
        q.push(0);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int curr = q.front();
                q.pop();
                if(curr == dest)
                    return level;
                for(int nei: graph[curr])
                {
                    if(visited[nei])
                        continue;
                    visited[nei] = true;
                    q.push(nei);
                }   
            }
            level++;
        }
        return -1;
    }

public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    return bfs(V, adj, X);
	}
	
	// BFS, T.C.=O(V+E), S.C.=O(V+E)
};
