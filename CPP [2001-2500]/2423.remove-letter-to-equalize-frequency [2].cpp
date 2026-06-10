class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> mp1; // char -> freq
        for(char ch: word)
            mp1[ch]++;
        map<int, int> mp2; // freq -> num of distinct chars with that freq
        for(auto it: mp1)
            mp2[it.second]++;
        
        if(mp2.size() > 2) // cannot have more than 2 distinct freqs
            return false;
        
        auto it = mp2.begin();
        int freq1 = it->first;
        int charCount1 = it->second;

        if(mp2.size() == 1)
            return (freq1 == 1 || charCount1 == 1) ? true : false;

        if(freq1 == 1 && charCount1 == 1)
            return true;

        it++;
        int freq2 = it->first;
        int charCount2 = it->second;

        if(abs(freq1 - freq2) != 1)
            return false;
        if(charCount2 == 1)
            return true;
            
        return false;
    }
};