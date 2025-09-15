class Solution {
private:
    typedef long long int lli;

    string intToBinStr(lli n){
        string str = n == 0 ? "0" : "";
        while(n > 0){
            str += n % 2;
            n /= 2;
        }

        reverse(str.begin(), str.end());
        return str;
    }

    bool isPalindrome(string s){
        for(int left = 0, right = s.length()-1; left < right; left++, right--)
            if(s[left] != s[right])
                return false;

        return true;
    }

public:
    // T.C.=O(n*log(n)), S.C.=O(log(n))
    int countBinaryPalindromes(long long n) {
        int count = 0;
        for(lli i=0; i<=n; i++)
            if(isPalindrome(intToBinStr(i)))
                count++;

        return count;
    }
};