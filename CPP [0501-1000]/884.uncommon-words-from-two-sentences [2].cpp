class Solution {
private:
    void extractWords(string& s, unordered_map<string, int>& mp){
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
    }

public:
    // T.C.=O(n1 + n2), S.C.=O(n1 + n2)
    vector<string> uncommonFromSentences(string s1, string s2) {
        // word -> freq
        unordered_map<string, int> mp;
        extractWords(s1, mp);
        extractWords(s2, mp);

        vector<string> ans;
        for(auto& [word, freq]: mp)
            if(freq == 1)
                ans.push_back(word);

        return ans;
    }
};