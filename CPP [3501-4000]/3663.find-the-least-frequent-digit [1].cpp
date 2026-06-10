class Solution {
public:
    // T.C.=O(10), S.C.=O(10)
    int getLeastFrequentDigit(int n) {
        vector<int> freq(10, 0);
        while(n > 0){
            freq[n % 10]++;
            n /= 10;
        }

        int minFreq = 100;
        int minFreqDigit = 0;
        for(int i=0; i<=9; i++)
            if(freq[i] > 0 && freq[i] < minFreq){
                minFreq = freq[i];
                minFreqDigit = i;
            }

        return minFreqDigit;
    }
};