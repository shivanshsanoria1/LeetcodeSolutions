class Solution {
public:
    // T.C.=O(n*100), S.C.=O(100)
    int maximumPopulation(vector<vector<int>>& logs) { 
        vector<int> population(101, 0);
        for(vector<int>& log: logs)
        {
            int birthYr = log[0];
            int deathYr = log[1];

            for(int i=birthYr; i<deathYr; i++)
                population[i - 1950]++;
        }

        int maxPop = 0;
        int maxPopYr = 1950;
        for(int i=0; i<=100; i++)
            if(population[i] > maxPop)
            {
                maxPop = population[i];
                maxPopYr = i + 1950;
            }

        return maxPopYr;
    }
};

// index: year
// 0: 1950, 1: 1951, 2: 1952, ..., 99: 2049, 100: 2050