class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, pair<int ,int>> mp; // word -> {freq in s1, freq in s2}

        string word = "";
        for(char ch: s1)
        {
            if(ch == ' ')
            {
                mp[word].first++;
                word = "";
            }
            else
                word += ch;
        }
        mp[word].first++;
        
        word = "";
        for(char ch: s2)
        {
            if(ch == ' ')
            {
                mp[word].second++;
                word = "";
            }
            else
                word += ch;
        }
        mp[word].second++;

        vector<string> ans;
        for(auto it: mp)
        {
            int freq1 = it.second.first;
            int freq2 = it.second.second;
            if((freq1 == 1 && freq2 == 0) || (freq1 == 0 && freq2 == 1))
                ans.push_back(it.first);
        }

        return ans;
    }
};