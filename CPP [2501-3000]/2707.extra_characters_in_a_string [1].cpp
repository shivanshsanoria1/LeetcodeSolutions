class Solution {
private:
    int solve(vector<string>& dict, string& s, int i, vector<int>& dp){
        if(i == s.length())
            return 0;

        if(dp[i] != -1)
            return dp[i];

        // skipping the char at index i
        int res = 1 + solve(dict, s, i + 1, dp);

        // not skipping the char at index i
        // check if the substring starting at index i and 
        // of the same length as 'word' matches with 'word'
        // if yes, move to the next recursive call starting at index i + word.length()
        for(string& word: dict)
            if(i + word.length() <= s.length() && s.substr(i, word.length()) == word)
                res = min(res, solve(dict, s, i + word.length(), dp));

        dp[i] = res;
        return dp[i];
    }

public:
    // T.C.=O(n*d*(n + m)), S.C.=O(n)
    // n: length of string s, d: num of words in dictionary[]
    // m: max length of word in dictionary
    // DP: Memoization
    int minExtraChar(string s, vector<string>& dictionary) { 
        vector<int> dp(s.length(), -1);

        return solve(dictionary, s, 0, dp);
    }
};

// similar [139. word-break]