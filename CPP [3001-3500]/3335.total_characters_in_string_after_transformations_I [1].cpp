class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n + 26*t), S.C.=O(26)
    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch - 'a']++;
        
        while(t--)
        {
            vector<int> temp(26, 0);
            // each char becomes the next char in sequence
            for(int i=1; i<26; i++)
                temp[i] = freq[i-1];
            
            // all z's becomes a's and b's
            temp[0] = freq[25];
            temp[1] = (temp[1] + freq[25]) % MOD;

            // update the freq[]
            freq = temp;
        }

        int sum = 0;
        for(int i=0; i<26; i++)
            sum = (sum + freq[i]) % MOD;

        return sum;
    }
};