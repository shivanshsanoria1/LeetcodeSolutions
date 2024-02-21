class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n=s.length();
        int left = n/2 - 1;
        int right = n % 2 == 0 ? n/2 : n/2 + 1;
        while(left >= 0 && right < n)
        {
            if(s[left] < s[right])
                s[right] = s[left];
            else if(s[left] > s[right])
                s[left] = s[right];
            left--;
            right++;
        }
        return s;
    }
};
/*
# for even length array: left = n/2 - 1, right = n/2
# for odd length array: left = n/2 - 1, mid = n/2, right = n/2 + 1
*/