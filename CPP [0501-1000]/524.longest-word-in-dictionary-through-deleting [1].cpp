class Solution {
public:
    // T.C.=O(n*min(w, l)), S.C.=O(1)
    // n: size of dictionary[], w: max length of a word in dictionary[]
    // l: length of string s
    // 2-pointer
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for(string& word: dictionary)
        {
            int i = 0, j = 0;
            while(i < s.length() && j < word.length())
            {
                if(s[i] == word[j])
                    j++;
                i++;
            }

            if(j == word.length())
            {
                if(word.length() > ans.length())
                    ans = word;
                else if(word.length() == ans.length() && word < ans)
                    ans = word;
            }
        }

        return ans;
    }
};