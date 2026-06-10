class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    string smallestPalindrome(string s) {
        int n = s.length();

        string part1 = s.substr(0, n/2);
        sort(part1.begin(), part1.end());

        string part2 = part1;
        reverse(part2.begin(), part2.end());
        
        // center-char in case of odd length palindrome
        if(n % 2 == 1)
            part1 += s[n/2];

        return part1 + part2;
    }
};