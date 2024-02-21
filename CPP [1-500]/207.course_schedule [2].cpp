class Solution {
public:
    bool isCyclic(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& pathVisited, int curr){
        visited[curr] = true;
        pathVisited[curr] = true;
        for(int nei: graph[curr])
        {
            // neighbour has been path visited, ie, cycle found
            if(pathVisited[nei]) 
                return true;
            // for unvisited neighbours continue the recursion, if cycle is found then return true
            if(!visited[nei] && isCyclic(graph, visited, pathVisited, nei))
                return true;
        }
        // unmark the curr vertex from path visited
        pathVisited[curr] = false;
        return false; // cycle not found
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> graph(n);
        for(auto& it: prerequisites) // build the graph
            graph[it[0]].push_back(it[1]);
        // keeps track of visited vertices in the entire graph
        vector<bool> visited(n, false);
        // keeps track of visited vertices in the curr path
        vector<bool> pathVisited(n, false);
        for(int i=0; i<n; i++)
            if(!visited[i] && isCyclic(graph, visited, pathVisited, i))
                return false;
        return true;
    }
};
// a -> b indicates 'a' must be taken before 'b'
// just find if the graph has a cycle or not