class Solution {
private:
    unordered_map<string, int> extractWords(string& s){
        // word -> freq
        unordered_map<string, int> mp;
        string word = "";
        s += " ";

        for(char ch: s)
        {
            if(ch == ' ')
            {
                mp[word]++;
                word = "";
            }
            else
                word += ch;
        }

        s.pop_back();

        return mp;
    }

public:
    // T.C.=O(n1 + n2), S.C.=O(n1 + n2)
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp1 = extractWords(s1);
        unordered_map<string, int> mp2 = extractWords(s2);

        vector<string> ans;

        for(auto& [word, freq]: mp1)
            if(freq == 1 && mp2.find(word) == mp2.end())
                ans.push_back(word);
        
        for(auto& [word, freq]: mp2)
            if(freq == 1 && mp1.find(word) == mp1.end())
                ans.push_back(word);

        return ans;
    }
};