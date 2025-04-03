class Solution {
private:
    bool isPalindrome(string s){
        for(int left = 0, right = s.length()-1; left < right; left++, right--)
            if(s[left] != s[right])
                return false;

        return true;
    }

public:
    // T.C.=O(n1^2 * n2^2 * (n1 + n2)), S.C.=O(n1 + n2)
    int longestPalindrome(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        int maxLen = 1;

        for(int i1=0; i1<n1; i1++)
        {
            string part1 = "";
            for(int j1=i1; j1<n1; j1++)
            {
                part1 += s[j1];

                if(isPalindrome(part1))
                    maxLen = max(maxLen, (int)part1.length());

                for(int i2=0; i2<n2; i2++)
                {
                    string part2 = "";
                    for(int j2=i2; j2<n2; j2++)
                    {
                        part2 += t[j2];

                        if(isPalindrome(part2))
                            maxLen = max(maxLen, (int)part2.length());

                        if(isPalindrome(part1 + part2))
                            maxLen = max(maxLen, (int)part1.length() + (int)part2.length());
                    }
                }
            }
        }

        return maxLen;
    }
};