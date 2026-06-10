class Solution {
private:
    bool isPalindrome(int n, int base){
        string s = "";
        while(n > 0)
        {
            s += '0' + n % base;
            n /= base;
        }

        int left = 0, right = s.length()-1;
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

public:
    bool isStrictlyPalindromic(int n) {
        for(int base=2; base<=n-2; base++)
            if(!isPalindrome(n, base))
                return false;
        return true;
    }
};