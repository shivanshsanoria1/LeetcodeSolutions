class Solution {
private:
    // returns the freq of lexicographically smallest char in string s
    int lexiSmallestFreq(string& s) {
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch - 'a']++;
        for(int i=0; i<26; i++)
            if(freq[i] > 0)
                return freq[i];
        return 0;
    }

public:
    // T.C.=O(q*w), S.C.=O(1)
    // q: size of queries[], w: size of words[]
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans;
        for(string& query: queries)
        {
            int currFreq = lexiSmallestFreq(query);
            int count = 0;
            for(string& word: words)
                if(currFreq < lexiSmallestFreq(word))
                    count++;
            ans.push_back(count);
        }
        return ans;
    }
};