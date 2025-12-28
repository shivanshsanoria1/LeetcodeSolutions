// https://www.geeksforgeeks.org/problems/articulation-point-1/1

class Solution {
private:
    void dfs(vector<int>graph[], vector<bool>& visited, int skipVertex, int curr){
        if(curr == skipVertex || visited[curr])
            return;
        visited[curr] = true;
        for(int nei: graph[curr])
            dfs(graph, visited, skipVertex, nei);
    }
    // returns true if graph remains connected after skipping the vertex 'skipVertex',
    // and false otherwise
    bool isConnected(int V, vector<int>graph[], int skipVertex){
        vector<bool> visited(V, false);
        // source vertex for dfs() is 0 (if 0 is not to be skipped) or 1 otherwise
        int src = 0 == skipVertex ? 1 : 0;
        dfs(graph, visited, skipVertex, src);
        for(int i=0; i<V; i++)
            if(i != skipVertex && !visited[i])
                return false;
        return true;
    }

public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        if(V == 1) // no Articulation point possible
            return {-1};
        vector<int> art; // Articulation points
        for(int i=0; i<V; i++)  
            if(!isConnected(V, adj, i))
                art.push_back(i);
        if(art.empty()) // no Articulation point found
            art.push_back(-1);
        return art;
    }
    // T.C.=O(V*(V+E)), S.C.=O(V)
};
