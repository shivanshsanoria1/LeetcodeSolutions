class Solution {
private:
    // sort strings in increasing order of length and
    // by increasing order of index if lengths are equal
    static bool cmp(pair<string, int>& p1, pair<string, int>& p2) {
        auto [s1, idx1] = p1;
        auto [s2, idx2] = p2;
        return s1.length() == s2.length() ? idx1 < idx2 : s1.length() < s2.length();
    }

public:
    string arrangeWords(string text) {
        // { {word, index} }
        vector<pair<string, int>> words;
        string word = "";
        text += " ";
        int idx = 0;
        for(char ch: text)
        {
            if(ch == ' ')
            {
                words.push_back({word, idx});
                word = "";
                idx++;
            }
            else
                word += tolower(ch);
        }
        text.pop_back();

        sort(words.begin(), words.end(), cmp);

        string ans = "";
        for(auto [word, idx]: words)
            ans += word + " ";
        ans.pop_back();
        ans[0] = toupper(ans[0]);

        return ans;
    }
};