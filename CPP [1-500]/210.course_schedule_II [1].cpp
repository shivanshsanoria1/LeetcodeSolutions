class Solution {
public:
    bool detectCycleUtil(vector<vector<int>> &graph, vector<int> &visited, int v){
        if(visited[v] == 2) // trying to process an already processing vertex, ie, cycle found
            return true;
        visited[v] = 2; // mark the curr vertex as processing
        for(int j=0; j<graph[v].size(); j++)
            // check for all un-processed vertices adjacent to the curr vertex for a cycle
            if(visited[graph[v][j]] != 1 && detectCycleUtil(graph, visited, graph[v][j]))
                return true;
        visited[v] = 1; // mark the curr vertex as processed
        return false; // no cycle found
    }

    bool detectCycle(vector<vector<int>> &graph, int n){
        vector<int> visited(n, 0); // initially all vertices are unvisited
        for(int i=0; i<n; i++)
            // curr vertex is unvisited and is in a cycle
            if(visited[i] == 0 && detectCycleUtil(graph, visited, i))
                return true;
        return false;
    }
    // 0: unvisited, 1: processed, 2: processing

    // Topological Sort
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &ans, int v){
        if(visited[v] == true) // already visited vertex
            return;
        visited[v] = true; // mark the curr vertex as visited
        for(int j=0; j<graph[v].size(); j++)
            // check for all unvisited vertices adjacent to the curr vertex
            if(visited[graph[v][j]] == false)
                dfs(graph, visited, ans, graph[v][j]);
        ans.push_back(v); // push the curr vertex in the ans before returning from dfs()
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) { // DFS
        vector<vector<int>> graph(numCourses);
        for(auto it: prerequisites) // build graph
        {
            int a = it[0];
            int b = it[1];
            graph[b].push_back(a); // edge from b to a
        }
        vector<int> ans;
        if(detectCycle(graph, numCourses)) // graph is cyclic
            return ans;
        vector<bool> visited(numCourses, false);
        for(int i=0; i<graph.size(); i++)
            if(visited[i] == false)
                dfs(graph, visited, ans, i);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
/*
# here, a -> b: means course a must be taken before course b
# for Topological Sort the graph must be DAG (Directed Acyclic Graph)
# instead of using stack and then popping its contents into the ans vector, 
# just use the ans vector and reverse it before returning the final ans  
*/