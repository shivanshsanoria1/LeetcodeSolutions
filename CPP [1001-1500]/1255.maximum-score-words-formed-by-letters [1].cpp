class Solution {
private:
    int solve(vector<string>& words, vector<int>& score, vector<int>& availableFreq, int i){
        if(i >= words.size())
            return 0;

        int exclude = solve(words, score, availableFreq, i+1);

        vector<int> currFreq(26, 0);
        int currWordScore = 0;
        for(char ch: words[i])
        {
            currFreq[ch - 'a']++;
            currWordScore += score[ch - 'a'];
        }
        
        for(int i=0; i<26; i++)
            if(currFreq[i] > availableFreq[i])
                return exclude;     
        
        for(int i=0; i<26; i++)
            availableFreq[i] -= currFreq[i];
        
        int include = solve(words, score, availableFreq, i+1);

        for(int i=0; i<26; i++)
            availableFreq[i] += currFreq[i];
        
        return max(exclude, currWordScore + include);
    }

public:
    // T.C.=O((l + 26) * 2^n), S.C.=O(n + 26)
    // n: size of words[], l: max length of word in words[]
    // Backtracking
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> availableFreq(26, 0);
        for(char letter: letters)
            availableFreq[letter - 'a']++;
        
        return solve(words, score, availableFreq, 0);
    }
};