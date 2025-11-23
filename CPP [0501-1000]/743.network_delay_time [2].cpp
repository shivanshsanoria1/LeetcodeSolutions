class Solution {
private:
    typedef pair<int, int> PI; // {time from a -> b, b}

public:
    void dij(vector<vector<PI>> &graph, vector<int> &minTimes, int src){ // Dijkstra algo.
        priority_queue<PI, vector<PI>, greater<PI>> pq; // min-heap
        pq.push({0, src}); // 0 time to reach from source to source
        while(!pq.empty())
        {
            int t1 = pq.top().first; // min time needed to reach 'a' from 'src'
            int a = pq.top().second;
            pq.pop();
            if(minTimes[a] != INT_MAX) // vertex 'a' is already visited
                continue;
            minTimes[a] = t1;
            for(auto ver: graph[a])
            {
                int b = ver.first;
                int t2 = ver.second; // time needed to reach 'b' from 'a'
                if(minTimes[b] != INT_MAX) // vertex 'b' is already visited
                    continue;
                pq.push({t1 + t2, b});
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
        dij(graph, minTimes, k);

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
/* 
min time needed to reach 'b' from 'src' = 
min time needed to reach 'a' from 'src', ie, t1 + 
time needed to reach 'b' from 'a', ie, t2 
*/