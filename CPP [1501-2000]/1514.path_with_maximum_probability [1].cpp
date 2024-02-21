class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for(int i=0; i<edges.size(); i++) // build graph
        {
            int a = edges[i][0];
            int b = edges[i][1];
            graph[a].push_back({b, succProb[i]});
            graph[b].push_back({a, succProb[i]});
        }
        vector<bool> visited(n, false);
        priority_queue<pair<double, int>> pq; // max-heap
        pq.push({1, start}); // probability to reach start vertex is 1
        while(!pq.empty())
        {
            auto [currProb, curr] = pq.top();
            pq.pop();
            visited[curr] = true; // mark the curr vertex as visited
            if(curr == end) // reached the end vertex
                return currProb;
            for(auto [nei, prob]: graph[curr])
            {
                if(visited[nei]) // already visited neighbour
                    continue;
                pq.push({currProb*prob, nei});
            }   
        }
        return 0; // end vertex is unreachable from the start vertex
    }
};
// Dijkstra's algo.