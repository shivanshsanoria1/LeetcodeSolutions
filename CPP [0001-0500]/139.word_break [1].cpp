class Solution {
private:
    bool solve(vector<string>& dict, string& s, int i, vector<int>& dp){
        // reached the end of original string 's'
        if(i == s.length()) 
            return true;
        
        if(dp[i] != -1)
            return dp[i];

        // check if the substring starting at index i and 
        // of the same length as 'word' matches with 'word'
        // if yes, move to the next recursive call starting at index i + word.length()
        for(string& word: dict)
            if(i + word.length() <= s.length() && s.substr(i, word.length()) == word && solve(dict, s, i + word.length(), dp))
            {
                dp[i] = 1;
                return true;
            }

        dp[i] = 0;
        return false;
    }

public:
    // T.C.=O(n*d*(n + m)), S.C.=O(n)
    // n: length of string s, d: size of wordDict[], 
    // m: max-length of word in wordDict[]
    // DP: Memoization
    bool wordBreak(string s, vector<string>& wordDict) { 
        vector<int> dp(s.length(), -1);

        return solve(wordDict, s, 0, dp);
    }
};

// similar: [2707. extra-characters-in-a-string]