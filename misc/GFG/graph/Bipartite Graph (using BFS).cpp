class Solution {
private:
    bool bfs(vector<int>graph[], vector<int>& colors, int src){
        queue<int> q;
        colors[src] = 0;
        q.push(src);
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int curr = q.front();
                q.pop();
                for(int nei: graph[curr])
                {
                    if(colors[nei] == -1)
                    {
                        colors[nei] = !colors[curr];
                        q.push(nei);
                    }
                    else if(colors[nei] == colors[curr])
                        return false;
                }   
            }
        }
        return true;
    }

public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> colors(V, -1);
	    for(int i=0; i<V; i++)
	        if(colors[i] == -1 && !bfs(adj, colors, i))
	            return false;
	   	return true;
	}
    // -1: no color, 0: color1, 1: color2
    // T.C.=O(V+E), S.C.=O(V)
};
