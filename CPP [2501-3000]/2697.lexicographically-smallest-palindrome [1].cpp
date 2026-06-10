class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n=s.length();
        int left = n/2 - 1;
        int right = n % 2 == 0 ? n/2 : n/2 + 1;
        string rightPalin = "";
        while(left >= 0 && right < n)
        {
            rightPalin += min(s[left], s[right]);
            left--;
            right++;
        }
        string leftPalin = rightPalin;
        reverse(leftPalin.begin(), leftPalin.end());
        return n % 2 == 0 ? leftPalin + rightPalin : leftPalin + s[n/2] + rightPalin;
    }
};
/*
# for even length array: left = n/2 - 1, right = n/2
# for odd length array: left = n/2 - 1, mid = n/2, right = n/2 + 1
*/