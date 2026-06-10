class Solution {
public:
    // T.C.=O(n*(l + 26)), S.C.=O(2*26)
    // n: size of words[], l: max length of a word in words[]
    vector<string> commonChars(vector<string>& words) {
        vector<int> prevFreq(26, INT_MAX);
        vector<int> currFreq(26, 0);

        for(string& word: words)
        {
            for(char ch: word) 
                currFreq[ch - 'a']++;

            for(int i=0; i<26; i++)
            {
                prevFreq[i] = min(prevFreq[i], currFreq[i]); 
                currFreq[i] = 0; 
            }
        }

        vector<string> ans;
        
        for(int i=0; i<26; i++)
            while(prevFreq[i]--)
            {
                string s = "";
                s += i + 'a';
                ans.push_back(s);
            }

        return ans;
    }
};