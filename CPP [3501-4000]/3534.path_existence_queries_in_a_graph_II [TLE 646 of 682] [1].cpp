class Solution {
private:
    // returns the distance, ie, num of edges between src and dest nodes; 
    // -1 if they are not in the same component
    int bfs(vector<vector<int>>& graph, int src, int dest){
        int n = graph.size();
        vector<bool> visited(n, false);
        queue<int> q;

        visited[src] = true;
        q.push(src);
        int level = 0;

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int curr = q.front();
                q.pop();

                if(curr == dest)
                    return level;
                
                for(int nei: graph[curr])
                {
                    if(visited[nei])
                        continue;

                    visited[nei] = true;
                    q.push(nei);
                }
            }
            level++;
        }

        return -1;
    }

public:
    // T.C.=O(q*n^2), S.C.=O(n^2)
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(i != j && abs(nums[i] - nums[j]) <= maxDiff)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
        
        vector<int> ans;
        for(vector<int>& query: queries)
        {
            int a = query[0], b = query[1];
            ans.push_back(bfs(graph, a, b));
        }

        return ans;
    }
};