class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26, 0);
        for(char ch: chars)
            freq[ch - 'a']++;
            
        int ans = 0;
        for(string& word: words)
        {
            vector<int> tempFreq(26, 0);
            bool isGoodStr = true;
            for(char ch: word)
            {
                tempFreq[ch - 'a']++;
                if(tempFreq[ch - 'a'] > freq[ch - 'a'])
                {
                    isGoodStr = false;
                    break;
                }
            }
            if(isGoodStr)
                ans += word.length();
        }
        return ans;
    }
};