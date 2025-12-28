class Solution {
private:
    bool dfs(vector<int>graph[], vector<int>& colors, int parent, int curr){
        // curr color is set to 0 if parent vertex does not exist, 
        // and set to the opposite color of parent otherwise
        colors[curr] = parent == -1 ? 0 : !colors[parent];
        for(int nei: graph[curr])
        {
            // skip the neighbour who is the parent of curr vertex
            if(nei == parent) 
                continue;
            // neighbour and curr vertex have same color
            if(colors[nei] == colors[curr])
                return false;
            if(colors[nei] == -1 && !dfs(graph, colors, curr, nei))
                return false;
        }
        return true;
    }

public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> colors(V, -1);
	    for(int i=0; i<V; i++)
	        if(colors[i] == -1 && !dfs(adj, colors, -1, i))
	           return false;
	    return true;
	}
    // -1: no color, 0: color1, 1: color2
    // T.C.=O(V + E), S.C.=O(V)
};
