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
        for(int i=s.length()-1; i>=0; i--)
        {
            string prefix = s.substr(0, i+1);
            if(isPalindrome(prefix))
            {
                string suffix = s.substr(i+1);
                reverse(suffix.begin(), suffix.end());

                return suffix + s;
            }
        }

        return "";
    }
};

/*
# find the Longest-Palindromic-Prefix (LPP) of the input string s 
# suppose the LPP is in index range [0, i], then
  prefix: [0, i]
  suffix: [i+1, n-1]
# append reverse(suffix) to the beginning of input string s
  to make it palindromic
*/