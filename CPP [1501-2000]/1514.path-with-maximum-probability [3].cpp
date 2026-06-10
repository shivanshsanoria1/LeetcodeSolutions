class Solution {
public:
    // T.C.=O(n*E), S.C.=O(n + E)
    // SPFA (Shortest Path Faster Algo.)
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

        queue<int> q;
        vector<bool> isInQueue(n, false);
        q.push(src);
        isInQueue[src] = true;

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            isInQueue[curr] = false;

            for(auto [nei, prob]: graph[curr])
                if(maxProb[curr] * prob > maxProb[nei])
                {
                    maxProb[nei] = maxProb[curr] * prob;

                    if(isInQueue[nei])
                        continue;

                    q.push(nei);
                    isInQueue[nei] = true;
                }
        }

        return maxProb[dest];
    }
};

// SPFA is a improvement of Bellman Ford algo.
// T.C. of both are the same but SPFA has a better run-time