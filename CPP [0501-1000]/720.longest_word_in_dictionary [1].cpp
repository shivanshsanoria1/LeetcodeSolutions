class Solution {
public:
    // T.C.=O(n*l), S.C.=O(n)
    // n: size of words[], l: max length of word in words[]
    string longestWord(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());

        string ans = "";
        for(string& word: words)
        {
            bool canBeAns = true;
            
            // check if every prefix of 'word' exists in 'dict'
            for(int len=1; len < word.length(); len++)
                if(dict.find(word.substr(0, len)) == dict.end())
                {
                    canBeAns = false;
                    break;
                }

            if(canBeAns)
            {
                if(ans == "" || word.length() > ans.length())
                    ans = word;
                else if(word.length() == ans.length())
                    ans = min(ans, word);
            }
        }

        return ans;
    }
};