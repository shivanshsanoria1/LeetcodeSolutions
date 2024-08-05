class Solution {
public:
    // T.C.=O(n*log(n) + ??), S.C.=O(1)
    // Greedy
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());

        int limit = 0;
        int coinsAdded = 0;
        for(int coin: coins)
        {
            while(limit < target && limit + 1 < coin)
            {
                limit += limit + 1;
                coinsAdded++;
            }

            if(limit >= target)
                break;
            
            limit += coin;
        }

        while(limit < target)
        {
            limit += limit + 1;
            coinsAdded++;
        }

        return coinsAdded;
    }
};
// limit: we can make all the sums in range [0, limit]

// prerequisite: [1798. maximum-number-of-consecutive-values-you-can-make]
// similar: [330. patching-array]