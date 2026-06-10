class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    // T.C.=O(n), S.C.=O(2^5)
    int findTheLongestSubstring(string s) {
        // parity-hash; 0: even freq, 1: odd freq
        string hash = "00000";
        // vowel -> index in hash
        unordered_map<char, int> idx;
        idx['a'] = 0;
        idx['e'] = 1;
        idx['i'] = 2;
        idx['o'] = 3;
        idx['u'] = 4;

        // hash -> index of its 1st occurence in string s
        unordered_map<string, int> mp;
        int maxLen = 0;

        for(int i=0; i<s.length(); i++)
        {
            // flip the parity of curr vowel in hash
            if(isVowel(s[i]))
                hash[idx[s[i]]] = hash[idx[s[i]]] == '0' ? '1' : '0';

            // substring in index-range [0, i] is valid
            if(hash == "00000")
                maxLen = i+1;
            // substring in index-range [mp[hash] + 1, i] is valid
            else if(mp.find(hash) != mp.end())
                maxLen = max(maxLen, i - mp[hash]);
            // hash found for the 1st time in string s
            else
                mp[hash] = i;
        }

        return maxLen;
    }
};