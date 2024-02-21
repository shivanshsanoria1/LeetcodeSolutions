class Solution {
public:
    void dfs(vector<int>& edges, vector<int>& dist, int curr, int dis){
        if(curr == -1) // invalid vertex
            return;
        if(dist[curr] != -1) // already visited vertex
            return;
        dist[curr] = dis; // distance of curr vertex from source vertex
        dfs(edges, dist, edges[curr], dis + 1);
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);
        dfs(edges, dist1, node1, 0);
        dfs(edges, dist2, node2, 0);
        
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