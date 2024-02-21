class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) { // T.C.=O(n + 101), S.C.=O(101)
        vector<int> pop(101, 0);
        for(auto log: logs)
        {
            int birthYr = log[0];
            int deathYr = log[1];
            pop[birthYr - 1950]++;
            pop[deathYr - 1950]--;
        }
        int maxPop = pop[0];
        int maxPopYr = 1950;
        for(int i=1; i<101; i++) 
        {
            pop[i] += pop[i-1]; // calculate prefix sum
            if(pop[i] > maxPop) // curr population > max population
            {
                maxPop = pop[i]; // update the max population
                maxPopYr = i + 1950; // update the max population year
            }
        }
        return maxPopYr;
    }
};
// 0: 1950, 1: 1951, 2: 1952, ..., 99: 2049, 100: 2050