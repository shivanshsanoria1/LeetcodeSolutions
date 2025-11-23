class Solution {
private:
    bool solve(vector<string>& dict, string& s, int i){
        // reached the end of original string 's'
        if(i == s.length()) 
            return true;

        // check if the substring starting at index i and 
        // of the same length as 'word' matches with 'word'
        // if yes, move to the next recursive call starting at index i + word.length()
        for(string& word: dict)
            if(i + word.length() <= s.length() && s.substr(i, word.length()) == word && solve(dict, s, i + word.length()))
                return true;

        return false;
    }

public:
    // Recursion
    bool wordBreak(string s, vector<string>& wordDict) { 
        return solve(wordDict, s, 0);
    }
};