class Solution {
public:
    int solve(vector<string>& words, unordered_map<string, int>& dict, vector<int>& dp, int idx){
        if(dp[idx] != -1)
            return dp[idx];

        int maxLen = 0;
        for(int i=0; i<words[idx].length(); i++)
        {
            // form the next word by skipping the char at index i
            string nextWord = words[idx].substr(0, i) + words[idx].substr(i+1);
            if(dict.find(nextWord) != dict.end()) // found in set
                maxLen = max(maxLen, solve(words, dict, dp, dict[nextWord]));
        }

        dp[idx] = 1 + maxLen;
        return dp[idx];
    }

    int longestStrChain(vector<string>& words) { // Memoization, T.C.=O(n*l^2), S.C.=O(n)
        unordered_map<string, int> dict; // word -> index
        int n=words.size();
        for(int i=0; i<n; i++)
            dict[words[i]] = i;
    
        vector<int> dp(n, -1);
        int ans = 0;
        for(int i=0; i<n; i++)
            ans = max(ans, solve(words, dict, dp, i));
        return ans;
    }
};
// l: length of the longest word
// dp[i]: length of the longest chain possible starting from the word words[i]