class Solution {
public:
    // T.C.=O(n*E), S.C.=O(n)
    // modified Bellman-Ford algo.
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int src = start_node; // source
        int dest = end_node; // destination

        // initially probability of reaching any vertex from src vertex is 0
        vector<double> maxProb(n, 0); 
        // probability of reaching src vertex from itself is 1
        maxProb[src] = 1;

        // at max n-1 relaxations are required for n edges
        while(--n) 
        {
            bool isRelaxed = false;
            for(int i=0; i<edges.size(); i++)
            {
                int a = edges[i][0];
                int b = edges[i][1];
                double prob = succProb[i];

                if(maxProb[a] * prob > maxProb[b])
                {
                    maxProb[b] = maxProb[a] * prob;
                    isRelaxed = true;
                }
                if(maxProb[b] * prob > maxProb[a])
                {
                    maxProb[a] = maxProb[b] * prob;
                    isRelaxed = true;
                }
            }

            if(!isRelaxed) // no more relaxations 
                break; 
        }

        return maxProb[dest];
    }
};