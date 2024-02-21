class Solution {
public:
    void solve(vector<string>& dict, vector<string>& ans, string& currStr, string& s, int i){
        if(i == s.length())
        {
            string temp = currStr;
            temp.pop_back(); // remove the last space
            ans.push_back(temp);
            return;
        }
        for(string word: dict)
            if(s.substr(i, word.length()) == word)
            {
                currStr += word + ' ';
                solve(dict, ans, currStr, s, i + word.length());
                int len = word.length() + 1;
                while(len--) // remove the 'word' and space from curr str
                    currStr.pop_back();
            }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) { // Recursion
        vector<string> ans;
        string currStr;
        solve(wordDict, ans, currStr, s, 0);
        return ans;
    }
};