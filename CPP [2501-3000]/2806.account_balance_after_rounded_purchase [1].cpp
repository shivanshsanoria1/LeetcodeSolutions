class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        if(purchaseAmount % 10 == 0)
            return 100 - purchaseAmount;
        int v1 = 10 * (purchaseAmount / 10);
        int v2 = v1 + 10;
        return abs(purchaseAmount - v1) < abs(purchaseAmount - v2) ? 100 - v1 : 100 - v2;
    }
};