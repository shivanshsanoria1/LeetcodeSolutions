class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int left = 0; 
        for(int right=0; right<s.length(); right++)
            if(s[right] == ' ') // word found
            {
                reverse(s.begin() + left, s.begin() + right); // reverse the word
                left = right + 1; // update left
            }
        reverse(s.begin() + left, s.end()); // revrese the last word
        return s;
    }
};
// 'left' marks the start of a word and 'right' marks the end