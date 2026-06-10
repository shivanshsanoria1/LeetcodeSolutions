class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> mp; // char -> freq
        for(char ch: word)
            mp[ch]++;
        for(char ch: word)
        {
            mp[ch]--; // decrement the freq of curr char in map
            auto it = mp.begin();
            // find the 1st freq, if found to be 0, use 2nd freq as 1st freq
            int freq1 = (it->second == 0) ? (++it)->second : it->second;
            bool flag = true;
            for(auto it: mp)
            {
                if(it.second == 0) // skip the 0 freq
                    continue;
                if(it.second != freq1) // unequal freqs found
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                return true;
            mp[ch]++; // restore the freq of curr char in map
        }
        return false;
    }
};