class Solution {
public:
    // returns the height of tree with 'src' as root node
    int bfs(vector<vector<int>>& graph, int n, int minHeight, int src){
        queue<int> q;
        vector<bool> visited(n, false);
        visited[src] = true;
        q.push(src);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            level++;
            // curr height exceeded the min height found so far,
            // so no need to continue the bfs()
            if(level > minHeight)
                return level;
            while(size--)
            {
                int curr = q.front();
                q.pop();
                for(int nei: graph[curr])
                {
                    if(visited[nei])
                        continue;
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }
        return level;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto edge: edges) // build graph
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> ans;
        int minHeight = n;
        for(int i=0; i<n; i++)
        {
            int height = bfs(graph, n, minHeight, i);
            if(height < minHeight) // new min height found
            {
                minHeight = height; // update min height
                ans.clear();
                ans.push_back(i);
            }
            else if(height == minHeight) // another min height found
                ans.push_back(i);
        }
        return ans;
    }
};