class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        while(k > 0 && numOnes > 0)
        {
            ans++;
            numOnes--;
            k--;
        }
        while(k > 0 && numZeros > 0)
        {
            numZeros--;
            k--;
        }
        while(k > 0 && numNegOnes > 0)
        {
            ans--;
            numNegOnes--;
            k--;
        }
        return ans;
    }
};