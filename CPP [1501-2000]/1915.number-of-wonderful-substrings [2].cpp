class Solution {
public:
    // T.C.=O(10*n), S.C.=O(2^10)
    // Bit-manipulation
    long long wonderfulSubstrings(string word) {
        // parity of each char in bit form;
        // 0: even freq, 1: odd freq
        int hash = 0;
        // parity-hash -> freq
        vector<int> freq(1024, 0);
        // hash of empty string
        freq[hash]++;

        long long int count = 0;

        for(char ch: word)
        {
            // flip the parity of curr char
            hash = hash ^ (1 << (ch - 'a'));

            // count of prev substrings with the same parity-hash, ie,
            // num of substrings with 0 odd-freq chars 
            count += freq[hash];

            // generate all 10 possible hashes differing 
            // at exactly 1 position from the curr hash 
            for(int i=0; i<10; i++)
            {
                int hash1 = hash ^ (1 << i);
                // count of prev substrings with the parity-hash 
                // differing at exactly 1 position from curr hash, ie,
                // num of substrings with 1 odd-freq char
                count += freq[hash1];
            }

            freq[hash]++;
        }

        return count;
    }
};
// A ^ 0 = A
// A ^ 1 = not A