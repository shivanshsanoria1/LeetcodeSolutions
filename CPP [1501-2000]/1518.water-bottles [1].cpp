class Solution {
public:
    // T.C.=O(??), S.C.=O(1)
    int numWaterBottles(int numBottles, int numExchange) {
        int filled = numBottles;
        int exchange = numExchange;
        int empty = 0;
        int consumed = 0;
        
        while(filled + empty >= exchange)
        {
            // consume all the filled-bottles
            consumed += filled;
            // filled-bottles are now empty
            empty += filled;
            // exchange empty-bottles in groups of size 'exchange' for filled bottles
            filled = empty / exchange;
            // empty-bottles left after exchange
            empty %= exchange;
        }

        return consumed + filled;
    }
};