class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    bool hasSameDigits(string s) {
        while(s.length() > 2)
        {
            string temp = "";
            for(int i=0; i<s.length()-1; i++)
                temp += ((s[i] - '0') + (s[i+1] - '0')) % 10;

            s = temp;
        }

        return s[0] == s[1];
    }
};