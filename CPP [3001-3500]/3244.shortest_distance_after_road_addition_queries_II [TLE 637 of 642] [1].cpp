class Solution {
private:
    int bfs(vector<vector<int>>& graph){
        int n=graph.size();
        vector<bool> visited(n, false);
        queue<int> q;

        visited[0] = true;
        q.push(0);
        int steps = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int curr = q.front();
                q.pop();
                
                if(curr == n-1)
                    return steps;
                
                for(int nei: graph[curr])
                {
                    if(visited[nei])
                        continue;
                    visited[nei] = true;
                    q.push(nei);
                }
            }
            steps++;
        }
        
        return -1;
    }

    
public:
    // T.C.=O(q*(V + E))
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for(int i=0; i<n-1; i++)
            graph[i].push_back(i+1);
        
        vector<int> ans;
        for(vector<int>& query: queries)
        {
            int a = query[0];
            int b = query[1];
            graph[a].push_back(b);
            
            ans.push_back(bfs(graph));
        }
        
        return ans;
    }
};