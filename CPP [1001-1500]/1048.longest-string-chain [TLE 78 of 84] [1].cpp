class Solution {
public:
    int solve(vector<string>& words, unordered_map<string, int>& dict, int idx){
        int maxLen = 0;
        for(int i=0; i<words[idx].length(); i++)
        {
            // form the next word by skipping the char at index i
            string nextWord = words[idx].substr(0, i) + words[idx].substr(i+1);
            if(dict.find(nextWord) != dict.end()) // found in set
                maxLen = max(maxLen, solve(words, dict, dict[nextWord]));
        }
        return 1 + maxLen;
    }

    int longestStrChain(vector<string>& words) { // Recursion
        unordered_map<string, int> dict; // word -> index
        for(int i=0; i<words.size(); i++)
            dict[words[i]] = i;
        
        int ans = 0;
        for(int i=0; i<words.size(); i++)
            ans = max(ans, solve(words, dict, i));
        return ans;
    }
};