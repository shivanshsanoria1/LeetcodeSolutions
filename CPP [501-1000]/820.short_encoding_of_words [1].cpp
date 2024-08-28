class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int minimumLengthEncoding(vector<string>& words) {
        // remove duplicate words
        unordered_set<string> dict(words.begin(), words.end());

        // remove all proper-suffixes of each word from dict.
        for(string& word: words)
            for(int i=1; i<word.length(); i++)
                dict.erase(word.substr(i));
        
        // words remaining in dict. are not a suffix of any other word
        // +1 is done since '#' char is used as a spearator
        int ans = 0;
        for(string word: dict)
            ans += word.length() + 1;
        
        return ans;
    }
};