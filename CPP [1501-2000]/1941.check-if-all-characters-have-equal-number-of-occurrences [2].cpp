class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mp; // char -> freq
        for(char ch: s)
            mp[ch]++;
        int f = mp.begin()->second; // 1st freq
        for(auto it: mp)
            if(it.second != f) // non-matching freqs found
                return false;
        return true;
    }
};