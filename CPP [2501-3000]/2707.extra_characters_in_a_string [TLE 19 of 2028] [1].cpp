class Solution {
private:
    int solve(vector<string>& dict, string& s, int i){
        if(i == s.length())
            return 0;

        // skipping the char at index i
        int res = 1 + solve(dict, s, i + 1);

        // not skipping the char at index i
        // check if the substring starting at index i and 
        // of the same length as 'word' matches with 'word'
        // if yes, move to the next recursive call starting at index i + word.length()
        for(string& word: dict)
            if(i + word.length() <= s.length() && s.substr(i, word.length()) == word)
                res = min(res, solve(dict, s, i + word.length()));

        return res;
    }

public:
    // Recursion
    int minExtraChar(string s, vector<string>& dictionary) { 
        return solve(dictionary, s, 0);
    }
};