class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    int maxProduct(int n) {
        int maxDig1 = 0, maxDig2 = 0;
        while(n > 0)
        {
            int dig = n % 10;

            if(dig >= maxDig1)
            {
                maxDig2 = maxDig1;
                maxDig1 = dig;
            }
            else if(dig > maxDig2)
                maxDig2 = dig;

            n /= 10;
        }

        return maxDig1 * maxDig2;
    }
};