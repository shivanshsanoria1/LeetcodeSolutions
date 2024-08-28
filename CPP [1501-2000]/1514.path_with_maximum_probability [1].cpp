class Solution {
public:
    // T.C.=O(n + E*log(n)), S.C.=O(E + n)
    // modified Dijkstra's algo.
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int src = start_node; // source
        int dest = end_node; // destination

        // weighted undirected graph
        vector<vector<pair<int, double>>> graph(n);
        for(int i=0; i<edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            graph[a].push_back({b, succProb[i]});
            graph[b].push_back({a, succProb[i]});
        }

        // initially probability of reaching any vertex from src vertex is 0
        vector<double> maxProb(n, 0); 
        // probability of reaching src vertex from itself is 1
        maxProb[src] = 1;

        // max-heap; {prob, vertex}
        priority_queue<pair<double, int>> pq; 
        pq.push({maxProb[src], src});

        while(!pq.empty())
        {
            int curr = pq.top().second;
            pq.pop();

            if(curr == dest) // reached the dest vertex
                break;

            for(auto [nei, prob]: graph[curr])
                if(maxProb[curr] * prob > maxProb[nei])
                {
                    maxProb[nei] = maxProb[curr] * prob;
                    pq.push({maxProb[nei], nei});
                }
        }

        return maxProb[dest];
    }
};