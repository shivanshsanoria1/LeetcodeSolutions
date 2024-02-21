class Solution {
private:
    typedef long long int lli;

public:
    int bfs(vector<vector<int>> &graph, int src){
        int n=graph.size();
        vector<bool> visited(n, false);
        queue<int> q;
        visited[src] = true;
        q.push(src);
        int count = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            count++;
            for(int nei: graph[curr])
            {
                if(visited[nei])
                    continue;
                visited[nei] = true;
                q.push(nei);
            }
        }
        return count;
    }

    int maximumDetonation(vector<vector<int>>& bombs) { // BFS
        int n=bombs.size();
        vector<vector<int>> graph(n); // bomb i can detonate the bombs graph[i]
        for(int i=0; i<n; i++) // build graph
        {
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r1 = bombs[i][2];
            for(int j=0; j<n; j++)
            {
                if(i == j) // skip the bomb detonating itself
                    continue;
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                //int r2 = bombs[j][2];
                if((lli)(x1-x2)*(x1-x2) + (lli)(y1-y2)*(y1-y2) <= (lli)r1*r1)
                    graph[i].push_back(j);
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++)
            ans = max(ans, bfs(graph, i));
        return ans;
    }
};
/*
# in the graph A -> B means bomb A can detonate bomb B
# a bomb A(x1,y1,r1) can detonate a bomb B(x2,y2,r2) if 
  the distance between A and B is less than or equal to the radius of A, ie, r1
# sqrt((x1-x2)^2 + (y1-y2)^2) <= r1 
  -> (x1-x2)^2 + (y1-y2)^2 <= r1^2
*/