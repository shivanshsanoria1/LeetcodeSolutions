class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<bool> isFilled(n, false);

        for(int fruit: fruits)
            for(int i=0; i<n; i++)
                if(!isFilled[i] && baskets[i] >= fruit)
                {
                    isFilled[i] = true;
                    break;
                }

        return count(isFilled.begin(), isFilled.end(), false);
    }
};