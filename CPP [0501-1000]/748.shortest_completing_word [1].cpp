class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> freq(26, 0);
        for(char ch: licensePlate)
        {
            if(ch >= 'a' && ch <= 'z')
                freq[ch - 'a']++;
            else if(ch >= 'A' && ch <= 'Z')
                freq[ch - 'A']++;
        }

        string ans = "";
        for(string& word: words)
        {
            vector<int> wordFreq(26, 0);
            for(char ch: word)
                wordFreq[ch - 'a']++;

            bool found = true;
            for(int i=0; i<26; i++)
                if(freq[i] > wordFreq[i])
                {
                    found = false;
                    break;
                }

            if(!found)
                continue;
            if(ans == "" || word.length() < ans.length())
                ans = word;
        }
        return ans;
    }
};