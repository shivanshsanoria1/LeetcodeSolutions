class Solution {
public:
    int solve(vector<string>& dict, string& s, int i){
        if(i >= s.length())
            return 0;

        // skipping the char at index i
        int minSkipped = 1 + solve(dict, s, i + 1);

        // not skipping the char at index i
        for(string& word: dict)
            if(s.substr(i, word.length()) == word)
                minSkipped = min(minSkipped, solve(dict, s, i + word.length()));

        return minSkipped;
    }

    int minExtraChar(string s, vector<string>& dictionary) { // Recursion
        return solve(dictionary, s, 0);
    }
};