class Solution {
public:
    void bfs(vector<int>& edges, vector<int>& dist, int source){
        int n=edges.size();
        queue<int> q;
        vector<bool> visited(n);
        visited[source] = true; // mark the source vertex as visited
        q.push(source);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int curr = q.front();
                q.pop();
                dist[curr] = level; // distance of curr vertex from source vertex
                // neighbour of curr vertex does not exist or is already visited
                if(edges[curr] == -1 || visited[edges[curr]]) 
                    continue;
                visited[curr] = true; // mark the curr vertex as visited
                q.push(edges[curr]);
            }
            level++;
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);
        bfs(edges, dist1, node1);
        bfs(edges, dist2, node2);
        
        int minDist = INT_MAX;
        int ans = -1;
        for(int i=0; i<n; i++)
        {
            if(dist1[i] == -1 || dist2[i] == -1)
                continue;
            if(minDist > max(dist1[i], dist2[i]))
            {
                minDist = max(dist1[i], dist2[i]);
                ans = i;
            }
        }
        return ans;
    }
};