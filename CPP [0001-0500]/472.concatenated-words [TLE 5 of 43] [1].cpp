class Solution {
public:
    // returns true if string s can be made by concatenating words from dict
    bool solve(vector<string>& dict, string& s, int i){
        if(i == s.length()) // reached the end of original string 's'
            return true;
        for(string& word: dict)
        {
            // string s should be made up by concatenating atleast 2 words from dict
            if(word == s) // skip the word matching with string s
                continue;
            // check if the substring starting at index i and of the same length as 'word' matches with 'word'
            // if yes, move to the next recursive call starting at index i + word.length()
            if(s.substr(i, word.length()) == word && solve(dict, s, i + word.length()))
                return true;
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) { // Recursion
        vector<string> ans;
        for(string& word: words)
            if(solve(words, word, 0))
                ans.push_back(word);
        return ans;
    }
};

// similar to Leetcode-137 "word break"