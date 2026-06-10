class Solution {
public:
    // returns true if string s can be made by concatenating words from dict
    bool solve(unordered_set<string>& dict, unordered_map<string, bool>& dp, string& s){
        if(dp.find(s) != dp.end()) // found result in dp
            return dp[s];
        for(int i=0; i<s.length(); i++)
        {
            string prefix = s.substr(0, i); // starts at index 0 and is of length i
            string suffix = s.substr(i); // starts at index i till the end of string s
            bool foundPrefix = dict.find(prefix) != dict.end();
            bool foundSuffix = dict.find(suffix) != dict.end();
            // if prefix is found in dict -> if suffix is found in dict -> return true
            // if prefix is found in dict -> if suffix is not found in dict -> 
            // recursively check for suffix -> if true -> return true
            if(foundPrefix && (foundSuffix || solve(dict, dp, suffix)))
            {
                dp[s] = true; // store the result in dp
                return dp[s];
            }
        }
        dp[s] = false; // store the result in dp
        return dp[s];
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) { // Memoization
        vector<string> ans;
        unordered_set<string> dict(words.begin(), words.end());
        unordered_map<string, bool> dp;
        for(string& word: words)
            if(solve(dict, dp, word))
                ans.push_back(word);
        return ans;
    }
};