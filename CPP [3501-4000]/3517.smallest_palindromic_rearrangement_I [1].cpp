class Solution {
public:
    // T.C.=O(n), S.C.=O(26)
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch - 'a']++;
        
        string part1 = "", part2 = "";
        char centerChar = '_';
        for(int i=0; i<26; i++)
        {
            char ch = i + 'a';
            int charCount = freq[i]/2;

            while(charCount--)
            {
                part1 += ch;
                part2 += ch;
            }

            // center-char not found and curr-char freq is odd
            if(centerChar == '_' && freq[i] % 2 == 1)
                centerChar = ch;
        }

        // center-char found
        if(centerChar != '_')
            part1 += centerChar;
        
        reverse(part2.begin(), part2.end());

        return part1 + part2;
    }
};