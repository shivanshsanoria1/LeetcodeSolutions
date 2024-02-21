class Solution {
public:
    int dfs(vector<vector<int>> &graph, vector<bool> &hasApple, vector<bool> &visited, int v)
    {
        if(visited[v])
            return 0;
        visited[v] = true;
        int count = 0;
        for(int ver: graph[v])
            count += dfs(graph, hasApple, visited, ver);
        // if the curr vertex has apple or any of its childs have apple (count > 0)
        // then the curr vertex must return with +1 count as it is present in the path with apples
        return (hasApple[v] || count > 0) ? 1 + count : count;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for(auto edge: edges) // build graph
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool> visited(n, false);
        int count = dfs(graph, hasApple, visited, 0);
        // if there is atleast 1 apple in tree (count > 0) 
        // then -1 is done to nullify the effect of +1 returned by root node
        // which is then multiplied by 2 as each edge is visited 2 times
        return count > 0 ? 2 * (count - 1) : 0;
    }
};