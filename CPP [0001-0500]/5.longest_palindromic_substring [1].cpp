class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(), start_index=0, max_len_palin=1;
        //true value at dp[i][j] indicates string starting from index i and ending at index j is palindrome
        //false value at dp[i][j] indicates string starting from index i and ending at index j is not palindrome
        vector<vector<bool>> dp(n,vector<bool> (n,false)); //assume all substrings are not palindrome
        //fill all positions of the form dp[i][i] and dp[i][i+1] (strings of length 1 and 2)
        for(int i=0; i<n; i++)
        {
            dp[i][i]=true; //strings starting from index i and ending at index i (strings of length=1) are palindrome
            if(i+1 < n && s[i]==s[i+1]) //check whether the string starting from index i and ending at index i+1 (string of length=2) is palindrome
            {
                dp[i][i+1]=true;
                max_len_palin=2;
                start_index=i;
            }
        }
        //all elements below the diagonal (dp[i][j] where i>j) remain false
        for(int j=2; j<n; j++) //starting filling elements column wise starting from column 2
        {
            for(int i=0; i<=j-2; i++)
            {
                if(s[i]==s[j] && dp[i+1][j-1]==true) //string starting from index i and ending at index j is palindrome if the char. at index
                { //i and j are equal and the substring starting from index i+1 and ending at index j-1 is palindrome
                    dp[i][j]=true;
                    if(j-i+1 > max_len_palin)
                    {
                        max_len_palin=j-i+1;
                        start_index=i;
                    }
                }
            }
        }
        return s.substr(start_index, max_len_palin);
    }
};