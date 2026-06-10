class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;

        for(int cost: costs)
        {
            if(coins - cost >= 0)
            {
                coins -= cost;
                count++;
            }
            else
                break;
        }

        return count;
    }
};