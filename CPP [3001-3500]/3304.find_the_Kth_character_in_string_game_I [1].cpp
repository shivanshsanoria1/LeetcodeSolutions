class Solution {
public:
    // T.C.=O(k*log(k)), S.C.=O(k)
    char kthCharacter(int k) {
        string word = "a";
        while(word.length() < k)
        {
            string temp = word;
            for(char& ch: temp)
                ch = (ch - 'a'+ 1) % 26 + 'a';

            word += temp;
        }

        return word[k-1];
    }
};