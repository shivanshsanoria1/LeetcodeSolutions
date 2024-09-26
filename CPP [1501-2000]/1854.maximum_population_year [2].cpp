class Solution {
public:
    // T.C.=O(n + 100), S.C.=O(100)
    // Line-Sweep algo.
    int maximumPopulation(vector<vector<int>>& logs) { 
        vector<int> mp(101, 0);
        for(vector<int>& log: logs)
        {
            int birthYr = log[0];
            int deathYr = log[1];

            mp[birthYr - 1950]++;
            mp[deathYr - 1950]--;
        }

        int maxPop = 0;
        int maxPopYr = 1950;
        int currCount = 0;
        for(int i=0; i<=100; i++) 
        {
            currCount += mp[i];
            if(currCount > maxPop)
            {
                maxPop = currCount;
                maxPopYr = i + 1950;
            }
        }

        return maxPopYr;
    }
};

// index: year
// 0: 1950, 1: 1951, 2: 1952, ..., 99: 2049, 100: 2050
// mp[i]: count of net births (+) or deaths (-) in the year (i + 1950)