class Solution {
private:
    typedef pair<int, int> PI;

public:
    void bfs(vector<vector<PI>> &graph, vector<int> &minTimes, int src){
        queue<int> q;
        minTimes[src] = 0; // 0 time to reach from source to source
        q.push(src);
        while(!q.empty())
        {
            int a = q.front();
            q.pop();
            for(auto ver: graph[a])
            {
                int b = ver.first;
                int t = ver.second;
                // minTimes[b] needs to be updated
                if(minTimes[b] > minTimes[a] + t)
                {
                    minTimes[b] = minTimes[a] + t;
                    q.push(b);
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<PI>> graph(n+1);
        for(auto time: times) // build graph
        {
            int a = time[0];
            int b = time[1];
            int t = time[2];
            graph[a].push_back({b, t}); // a -> b, edge weight = t
        }

        // initially it takes infinite time to reach all vertices from source (k)
        vector<int> minTimes(n+1, INT_MAX); // to store the min time taken to reach the ith vertex from source
        bfs(graph, minTimes, k); // start bfs() from source (k)

        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            // unvisited vertex left, ie, this vertex is unreachable from source
            if(minTimes[i] == INT_MAX)
                return -1;
            ans = max(ans, minTimes[i]);
        }
        return ans;
    }
};