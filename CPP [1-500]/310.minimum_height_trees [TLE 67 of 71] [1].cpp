class Solution {
private:
    // returns the height of tree with 'src' as root node
    int bfs(vector<vector<int>>& graph, int minHeight, int src){
        int n=graph.size();
        vector<bool> visited(n, false);
        queue<int> q;
        int level = -1;

        visited[src] = true;
        q.push(src);

        while(!q.empty())
        {
            int size = q.size();
            level++;
            // curr height exceedes the min height found so far,
            // so no need to continue bfs()
            if(level > minHeight)
                break;

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

public:
    // T.C.=O(n^2)
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        // build graph
        for(vector<int>& edge: edges) 
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> ans;
        int minHeight = n-1;

        for(int i=0; i<n; i++)
        {
            int height = bfs(graph, minHeight, i);

            // new min height found
            if(height < minHeight) 
            {
                minHeight = height;
                ans.clear();
                ans.push_back(i);
            }
            // another min height found
            else if(height == minHeight) 
                ans.push_back(i);
        }

        return ans;
    }
};
// T.C.=O(V*(V + E)) = O(n*(n + n-1)) = O(n^2)