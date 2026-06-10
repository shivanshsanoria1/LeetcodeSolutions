class Solution {
public:
    // T.C.=O(n + m), S.C.=O(m)
    // m: max val in costs[]
    // Counting-sort
    int maxIceCream(vector<int>& costs, int coins) {
        int maxVal = *max_element(costs.begin(), costs.end());

        vector<int> freq(maxVal + 1, 0);
        for(int cost: costs)
            freq[cost]++;
        
        int count = 0;
        for(int i=1; i<=maxVal; i++)
        {
            if(freq[i] == 0)
                continue;
            
            count += min(coins/i, freq[i]);
            coins -= i * min(coins/i, freq[i]);

            if(coins == 0)
                break;
        }

        return count;
    }
};