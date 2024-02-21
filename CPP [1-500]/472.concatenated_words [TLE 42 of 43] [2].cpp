class Solution {
public:
    // returns true if string s can be made by concatenating words from dict
    bool solve(unordered_set<string>& dict, string& s){
        for(int i=0; i<s.length(); i++)
        {
            string prefix = s.substr(0, i); // starts at index 0 and is of length i
            string suffix = s.substr(i); // starts at index i till the end of string s
            bool foundPrefix = dict.find(prefix) != dict.end();
            bool foundSuffix = dict.find(suffix) != dict.end();
            // if prefix is found in dict -> if suffix is found in dict -> return true
            // if prefix is found in dict -> if suffix is not found in dict -> 
            // recursively check for suffix -> if true -> return true
            if(foundPrefix && (foundSuffix || solve(dict, suffix)))
                return true;
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) { // Recursion
        vector<string> ans;
        unordered_set<string> dict(words.begin(), words.end());
        for(string& word: words)
            if(solve(dict, word))
                ans.push_back(word);
        return ans;
    }
};