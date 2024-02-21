class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // initially probability of reaching any vertex from start vertex is 0
        vector<double> maxProbs(n, 0); 
        // probability of reaching start vertex from start vertex is 1
        maxProbs[start] = 1;
        int r = n-1; // n-1 relaxations are required for n edges
        while(r--) 
        {
            bool flag = false;
            for(int i=0; i<edges.size(); i++) // build graph
            {
                int a = edges[i][0];
                int b = edges[i][1];
                double currProb = succProb[i];
                if(maxProbs[a] * currProb > maxProbs[b])
                {
                    maxProbs[b] = maxProbs[a] * currProb;
                    flag = true;
                }
                if(maxProbs[b] * currProb > maxProbs[a])
                {
                    maxProbs[a] = maxProbs[b] * currProb;
                    flag = true;
                }
            }
            if(!flag) // no more relaxations 
                break; 
        }
        return maxProbs[end];
    }
};
// Bellman-Ford algo.