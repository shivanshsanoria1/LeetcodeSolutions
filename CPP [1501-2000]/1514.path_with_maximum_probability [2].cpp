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

        // initially probability of reaching any vertex from start vertex is 0
        vector<double> maxProbs(n, 0); 
        // probability of reaching start vertex from start vertex is 1
        maxProbs[start] = 1;
        priority_queue<pair<double, int>> pq; // max-heap, {prob, vertex}
        pq.push({maxProbs[start], start});
        while(!pq.empty())
        {
            auto [currProb, curr] = pq.top();
            pq.pop();
            if(curr == end) // reached the end vertex
                return currProb;
            for(auto [nei, prob]: graph[curr])
                // perform relaxation  
                if(currProb * prob > maxProbs[nei])
                {
                    maxProbs[nei] = currProb * prob;
                    pq.push({maxProbs[nei], nei});
                }  
        }
        return maxProbs[end];
    }
};
// Dijkstra's algo.