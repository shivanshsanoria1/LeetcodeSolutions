class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());

        int limit = 0;
        for(int coin: coins)
        {
            if(limit + 1 < coin)
                break; 

            limit += coin;
        }

        // +1 is done since 0 must also be included
        return 1 + limit;
    }
};
/*
# suppose we can make all the nums in range [0, K] with some coins
# now if we take a coin with value C, then we can make the nums
  {0, 1, 2, ...k} and {0+C, 1+C, 2+C, ..., K+C}
# if value of C is in range [0, K+1], then these 2 ranges
  will combine to form the range [0, K+C]
# but if the value of C is in range [k+2, INF) then these 2 ranges 
  will never combine, thus leaving some nums (in between the 2 ranges) 
  which cannot be formed
  
# limit: we can make all the sums in range [0, limit]

# follow up: [330. patching-array]
# follow up: [2952. minimum-number-of-coins-to-be-added]
*/