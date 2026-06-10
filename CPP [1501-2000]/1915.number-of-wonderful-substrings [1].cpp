class Solution {
public:
    // T.C.=O(10*n), S.C.=O(2^10)
    // similar to Bit-manipulation
    long long wonderfulSubstrings(string word) {
        // parity of each char;
        // 0: even freq, 1: odd freq
        string hash(10, '0');
        // parity-hash -> freq
        unordered_map<string, int> mp;
        mp[hash]++;
        
        long long int count = 0;

        for(char ch: word)
        {
            // flip the parity of curr char
            hash[ch - 'a'] = hash[ch - 'a'] == '1' ? '0' : '1';
            
            // count of prev substrings with the same parity-hash, ie,
            // num of substrings with 0 odd-freq chars 
            count += mp[hash];

            // generate all 10 possible hashes differing 
            // at exactly 1 position from the curr hash 
            for(int i=0; i<10; i++)
            {
                string hash1 = hash;
                hash1[i] = hash[i] == '1' ? '0' : '1';
                // count of prev substrings with the parity-hash 
                // differing at exactly 1 position from curr hash, ie,
                // num of substrings with 1 odd-freq char
                count += mp[hash1];
            }

            mp[hash]++;
        }

        return count;
    }
};