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

        // Binary-search
        vector<int> ans;
        for(string& query: queries)
        {
            int currFreq = lexiSmallestFreq(query);
            int count = 0;

            int left = 0, right = wordFreq.size() - 1;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(wordFreq[mid] > currFreq)
                {
                    count += right - mid + 1;
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }

            ans.push_back(count);
        }
        return ans;
    }
};