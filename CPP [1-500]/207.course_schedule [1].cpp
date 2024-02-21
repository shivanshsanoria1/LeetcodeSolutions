class Solution {
public:
    bool isCyclic(vector<vector<int>>& graph, vector<int>& visited, int curr){
        // trying to process an already processing node, ie, cycle found
        if(visited[curr] == 2) 
            return true;
        visited[curr] = 2; // mark the curr node as processing
        for(int i=0; i<graph[curr].size(); i++)
            // check for all un-processed nodes adjacent to curr node for a cycle
            if(visited[graph[curr][i]] != 1 && isCyclic(graph, visited, graph[curr][i]) == true) 
                return true;
        visited[curr] = 1; // mark the curr node as processed
        return false; // no cycle found
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> graph(n);
        for(auto it: prerequisites) // build the graph
            graph[it[0]].push_back(it[1]);
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++)
            if(visited[i] == 0) // curr node is unvisited
                if(isCyclic(graph, visited, i) == true)
                    return false;
        return true;
    }
};
// a -> b: indicates that to take the course a we need to take course b first
// 0: unvisited, 1: processed, 2: processing node