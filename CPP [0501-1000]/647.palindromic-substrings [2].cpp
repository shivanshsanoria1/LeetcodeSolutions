class Solution {
public:
    // T.C=O(n^2), S.C.=O(n^2)
    int countSubstrings(string s) {
        int n=s.length();
        int count = 0;
        // dp of size n*n filled with false
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i=0; i<n; i++)
        {
            dp[i][i] = true;
            count++;
            if(i+1 < n && s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                count++;
            }
        }
        // starting filling elements column wise starting from column 2
        for(int j=2; j<n; j++)
            for(int i=0; i<=j-2; i++)
                if(s[i] == s[j] && dp[i+1][j-1]) 
                {
                    dp[i][j] = true;
                    count++;
                }
        
        return count;
    }
};

/*
# dp[i][j]: string starting from index i and ending at index j is palindrome or not
# initially assume all substrings are not palindrome
# dp[i][i] = true (since substring of length 1 is always palindrome)
# check all substrings of length 2 (dp[i][i+1]) are palindrome or not
# all elements below the main-diagonal (dp[i][j] where i>j) remain false
# string starting from index i and ending at index j is palindrome if the char. at index
  i and j are equal and the substring starting from index i+1 and ending at index j-1 is palindrome
*/