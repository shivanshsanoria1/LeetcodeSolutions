class Solution {
public:
    // T.C.=O(n2*(26 + w2) + n1*(26 + w1)), S.C.=O(26)
    // n1, n2: size of words1[], words2[]
    // w1, w2: max length of word in words1[], words2[]
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0);
        for(string& word: words2)
        {
            vector<int> freq(26, 0);
            for(char ch: word)
                freq[ch - 'a']++;

            for(int i=0; i<26; i++)
                maxFreq[i] = max(maxFreq[i], freq[i]);
        }

        vector<string> ans;
        for(string& word: words1)
        {
            vector<int> freq(26, 0);
            for(char ch: word)
                freq[ch - 'a']++;
            
            bool isUniversal = true;
            for(int i=0; i<26; i++)
                if(freq[i] < maxFreq[i])
                {
                    isUniversal = false;
                    break;
                }
            
            if(isUniversal)
                ans.push_back(word);
        }

        return ans;
    }
};