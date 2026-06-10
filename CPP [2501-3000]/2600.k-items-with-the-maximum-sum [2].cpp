class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;

        if(numOnes <= k)
        {
            ans += numOnes;
            k -= numOnes;
        }
        else
        {
            ans += k;
            return ans;
        }

        if(numZeros <= k)
            k -= numZeros;
        else
            return ans;

        if(numNegOnes <= k)
        {
            ans -= numNegOnes;
            k -= numNegOnes;
        }
        ans -= k;
        return ans;
    }
};