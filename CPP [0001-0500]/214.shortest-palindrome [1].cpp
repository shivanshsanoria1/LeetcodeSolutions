class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n), S.C.=O(n)
    // Rabin-Karp algo. (Rolling-Hash)
    string shortestPalindrome(string s) {
        long long int hash = 0;
        long long int revHash = 0;
        long long int mul = 1;
        // end index of the Longest-Palindromic-Prefix (LPP)
        int LLP_endIdx = -1;

        for(int i=0; i<s.length(); i++)
        {
            int charVal = (s[i] - 'a') + 1;

            hash = (hash * 26 + charVal) % MOD;

            revHash = (revHash + charVal * mul) % MOD;
            mul = (mul * 26) % MOD;

            // prefix in index range [0, i] is palindromic
            if(hash == revHash)
                LLP_endIdx = i;
        }
        
        string suffix = s.substr(LLP_endIdx + 1);
        reverse(suffix.begin(), suffix.end());

        return suffix + s;
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