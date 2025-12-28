class Solution {
private:
    bool isCyclic(vector<int> graph[], vector<bool>& visited, vector<bool>& pathVisited, 
    vector<bool>& inCycle, int curr){
        visited[curr] = true;
        pathVisited[curr] = true;
        for(int nei: graph[curr])
        {
            // neighbour has been path visited, ie, cycle found
            if(pathVisited[nei]) 
            {
                inCycle[curr] = true;
                return true;
            }
            // for unvisited neighbours continue the recursion, if cycle is found then return true
            if(!visited[nei] && isCyclic(graph, visited, pathVisited, inCycle, nei))
            {
                inCycle[curr] = true;
                return true;
            }
        }
        // unmark the curr vertex from path visited
        pathVisited[curr] = false;
        // cycle not found
        return false; 
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        // keeps track of visited vertices in the entire graph
        vector<bool> visited(V, false);
        // keeps track of visited vertices in the curr path
        vector<bool> pathVisited(V, false);
        // keeps track of vertices present in a cycle
        vector<bool> inCycle(V, false);

        for(int i=0; i<V; i++)
            if(!visited[i]) // check for unvisited vertices
                isCyclic(adj, visited, pathVisited, inCycle, i);

        vector<int> ans;
        for(int i=0; i<V; i++)
            if(!inCycle[i]) // vertex not present in cycle
                ans.push_back(i);
        return ans;
    }
};
/*
# just find the vertices not present in a cycle
*/