class Solution {
public:
    int solve(vector<string>& dict, vector<int>& dp, string& s, int i){
        if(i >= s.length()) // index out of bounds
            return 0;

        if(dp[i] != -1) // result found in dp
            return dp[i];

        // skipping the char at index i
        int minSkipped = 1 + solve(dict, dp, s, i + 1);

        // not skipping the char at index i
        for(string& word: dict)
            // check if the substring starting at index i and of the same length as 'word' matches with 'word'
            // if yes, move to the next recursive call starting at index i + word.length()
            if(s.substr(i, word.length()) == word)
                minSkipped = min(minSkipped, solve(dict, dp, s, i + word.length()));

        dp[i] = minSkipped; // store the result in dp
        return dp[i];
    }

    int minExtraChar(string s, vector<string>& dictionary) { // Memoization, T.C.=O(n*d*l), S.C.=O(n)
        vector<int> dp(s.length(), -1);
        return solve(dictionary, dp, s, 0);
    }
};
/*
# similar to Leetcode-139 'Word Break'
# n: length of string s
# d: num of words in dictionary
# l: max length of word in dictionary
*/