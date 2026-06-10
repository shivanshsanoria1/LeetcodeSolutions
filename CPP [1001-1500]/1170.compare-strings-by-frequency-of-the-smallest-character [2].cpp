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
    // T.C.=O(w*logw + q*logw), S.C.=O(w)
    // q: size of queries[], w: size of words[]
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> wordFreq;
        for(string& word: words)
            wordFreq.push_back(lexiSmallestFreq(word));
        sort(wordFreq.begin(), wordFreq.end());

        vector<int> ans;
        for(string& query: queries)
        {
            int currFreq = lexiSmallestFreq(query);
            // index of the first element with freq > currFreq
            int idx = upper_bound(wordFreq.begin(), wordFreq.end(), currFreq) - wordFreq.begin();
            ans.push_back(wordFreq.size() - idx);
        }
        return ans;
    }
};