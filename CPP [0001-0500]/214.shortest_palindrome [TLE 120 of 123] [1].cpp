class Solution {
private:
    bool isPalindrome(string& s){
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
    // T.C.=O(n^2), S.C.=O(n)
    string shortestPalindrome(string s) {
        if(isPalindrome(s))
            return s;
            
        reverse(s.begin(), s.end());

        for(int i=1; i<=s.length(); i++)
        {
            string part = s.substr(0, i);
            reverse(part.begin(), part.end());
            string str = s + part;

            if(isPalindrome(str))
            {
                reverse(str.begin(), str.end());
                return str;
            }
        }

        return "";
    }
};