class Solution {
public:
    // T.C.=O(26*n*l), S.C.=O(1)
    // n: size of words[], l: max length of a word in words[]
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;

        for(char ch='a'; ch<='z'; ch++)
        {
            int minFreq = INT_MAX;

            for(string& word: words)
            {
                int freq = 0;

                for(char w: word)
                    if(w == ch)
                        freq++;

                minFreq = min(minFreq, freq);
            }

            while(minFreq--)
            {
                string s = "";
                s += ch;
                ans.push_back(s);
            }
        }

        return ans;
    }
};