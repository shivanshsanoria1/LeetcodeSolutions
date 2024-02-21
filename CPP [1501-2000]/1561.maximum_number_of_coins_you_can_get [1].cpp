class Solution {
public:
    int maxCoins(vector<int>& piles) { // T.C.=O(n*logn), S.C.=O(1)
        sort(piles.begin(), piles.end());
        int n=piles.size() / 3;
        int sum = 0;
        for(int i=3*n-2; i >= n; i -= 2)
            sum += piles[i];
        return sum;
    }
};