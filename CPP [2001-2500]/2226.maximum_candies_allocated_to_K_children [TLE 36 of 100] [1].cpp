class Solution {
public:
    // T.C.=O(n*m), S.C.=O(1)
    // m: max element in candies[]
    int maximumCandies(vector<int>& candies, long long k) {
        long long int sum = 0;

        for(int candy: candies)
            sum += candy;

        if(k > sum)
            return 0;
        // each child gets 1 candy
        if(k == sum)
            return 1;

        int maxPile = *max_element(candies.begin(), candies.end());

        int ans = 0;

        for(int finalPile = maxPile; finalPile >= 1; finalPile--)
        {
            int children = 0;

            for(int candy: candies)
            {
                children += candy / finalPile;

                if(children >= k)
                    break;
            }
            
            if(children >= k)
            {
                ans = finalPile;
                break;
            }
        }

        return ans;
    }
};