class Solution {
public:
    // T.C.=O(n*10*2^10), S.C.=O(2^10)
    long long wonderfulSubstrings(string word) {
        // parity of each char;
        // 0: even freq, 1: odd freq
        string hash(10, '0');
        // hash -> freq
        unordered_map<string, int> mp;
        long long int count = 0;

        mp[hash]++;
        for(char ch: word)
        {
            hash[ch - 'a'] = hash[ch - 'a'] == '0' ? '1' : '0';

            for(auto [seenHash, freq]: mp)
            {
                int mismatch = 0;

                for(int i=0; i<10; i++)
                    if(seenHash[i] != hash[i])
                        mismatch++;

                if(mismatch <= 1)
                    count += freq;
            }

            mp[hash]++;
        }

        return count;
    }
};