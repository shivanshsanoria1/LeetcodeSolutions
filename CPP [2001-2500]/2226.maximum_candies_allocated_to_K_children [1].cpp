class Solution {
public:
    // T.C.=O(n*logm), S.C.=O(1)
    // m: max element in candies[]
    // Binary-Search
    int maximumCandies(vector<int>& candies, long long k) {
        long long int sum = 0;

        for(int candy: candies)
            sum += candy;

        if(k > sum)
            return 0;
        // each child gets 1 candy
        if(k == sum)
            return 1;

        int minPile = 1;
        int maxPile = *max_element(candies.begin(), candies.end());

        int ans = 0;

        while(minPile <= maxPile)
        {
            int midPile = minPile + (maxPile - minPile)/2;

            long long int children = 0;

            for(int candy: candies)
            {
                children += candy / midPile;

                if(children >= k)
                    break;
            }
            
            if(children >= k)
            {
                ans = midPile;
                minPile = midPile + 1;
            }
            else
                maxPile = midPile - 1;
        }

        return ans;
    }
};