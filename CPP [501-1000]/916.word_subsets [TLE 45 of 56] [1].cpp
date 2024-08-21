class Solution {
private:
    // returns true if the string 's2' is a subset of string 's1'
    bool isSubset(string& s1, string& s2){
        if(s1.length() < s2.length())
            return false;

        vector<int> freq(26, 0);
        for(char ch: s1)
            freq[ch - 'a']++;
        
        for(char ch: s2)
            if(--freq[ch - 'a'] < 0)
                return false;
        
        return true;
    }

public:
    // T.C.=O(n1*n2*(26 + w1 + w2)), S.C.=O(26)
    // n1, n2: size of words1[], words2[]
    // w1, w2: max length of word in words1[], words2[]
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        for(string& word1: words1)
        {
            bool isUniversal = true;
            for(string& word2: words2)
                if(!isSubset(word1, word2))
                {
                    isUniversal = false;
                    break;
                }
            
            if(isUniversal)
                ans.push_back(word1);
        }

        return ans;
    }
};