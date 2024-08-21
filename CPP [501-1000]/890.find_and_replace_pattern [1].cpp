class Solution {
public:
    // T.C.=O(n*p), S.C.=O(26)
    // n: size of words[], p: length of pattern
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(string& word: words)
        {
            // patten[i] -> word[i]
            vector<char> mapping1(26, '#');
            // word[i] -> patten[i]
            vector<char> mapping2(26, '#');
            bool match = true;

            for(int i=0; i<pattern.length(); i++)
            {
                if(mapping1[pattern[i] - 'a'] == '#')
                    mapping1[pattern[i] - 'a'] = word[i];
                else if(mapping1[pattern[i] - 'a'] != word[i])
                {
                    match = false;
                    break;
                }

                if(mapping2[word[i] - 'a'] == '#')
                    mapping2[word[i] - 'a'] = pattern[i];
                else if(mapping2[word[i] - 'a'] != pattern[i])
                {
                    match = false;
                    break;
                }
            }

            if(match)
                ans.push_back(word);
        }

        return ans;
    }
};