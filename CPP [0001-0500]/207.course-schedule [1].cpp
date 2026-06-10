class Solution {
private:
    bool isCyclic(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& pathVisited, int curr){
        if(visited[curr])
            return false;
            
        visited[curr] = true;
        pathVisited[curr] = true;

        for(int nei: graph[curr])
        {
            // neighbour has been visited in the curr path, ie, cycle found
            if(pathVisited[nei]) 
                return true;
            // continue the recursion and return true if cycle is found
            if(isCyclic(graph, visited, pathVisited, nei))
                return true;
        }

        // unmark the curr vertex from path visited
        pathVisited[curr] = false;
        // cycle not found
        return false; 
    }

public:
    // T.C.=O(n + p)
    // n: numCourses, p: size of prerequisites[]
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        // build-graph
        vector<vector<int>> graph(n);
        for(vector<int>& pre: prerequisites) 
        {
            int a = pre[0];
            int b = pre[1];
            graph[a].push_back(b);
        }
            
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
/*
# A -> B indicates: 
  # A is dependent on B
  # B is a prerequisite of A
  # To complete A we need to complete B first
# core-idea: just find if the graph has a cycle or not
*/