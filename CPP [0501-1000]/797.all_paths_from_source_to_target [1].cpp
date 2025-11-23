class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& path, int v){
        int n=graph.size();
        path.push_back(v);
        if(v == n-1) // reached the destination
            paths.push_back(path);
        for(int nei: graph[v])
        {
            dfs(graph, paths, path, nei);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph, paths, path, 0);
        return paths;
    }
};