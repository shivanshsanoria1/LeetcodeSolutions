class Solution {
public:
    bool solve(vector<string>& dict, string& s, int i){
        if(i == s.length()) // reached the end of original string 's'
            return true;
        for(string word: dict)
            // check if the substring starting at index i and of the same length as 'word' matches with 'word'
            // if yes, move to the next recursive call starting at index i + word.length()
            if(s.substr(i, word.length()) == word && solve(dict, s, i + word.length()))
                return true;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) { // Recursion
        return solve(wordDict, s, 0);
    }
};