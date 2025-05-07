class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    int maxProduct(int n) {
        vector<int> freq(10, 0);
        while(n > 0)
        {
            freq[n % 10]++;
            n /= 10;
        }

        int maxDig1 = 0, maxDig2 = 0;
        for(int i=9; i>=0; i--)
            while(freq[i] > 0)
            {
                if(maxDig1 == 0)
                    maxDig1 = i;
                else if(maxDig2 == 0)
                {
                    maxDig2 = i;
                    return maxDig1 * maxDig2;
                }

                freq[i]--;
            }

        return -1;
    }
};