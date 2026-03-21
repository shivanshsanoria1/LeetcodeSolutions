class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        for(string& word: words)
        {
            string curr = "";
            for(char ch: word)
            {
                if(ch == separator)
                {
                    if(curr.length() > 0)
                        ans.push_back(curr);
                    curr.clear();
                }
                else
                    curr += ch;
            }
            if(curr.length() > 0)
                ans.push_back(curr);
        }
        return ans;
    }
};