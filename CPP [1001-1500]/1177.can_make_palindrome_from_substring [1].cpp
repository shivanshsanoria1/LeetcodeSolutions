class Solution {
public:
    // T.C.=O(n*26 + q*26), S.C.=O(n*26)
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.length();
        // dp of size n*26 filled with 0's
        vector<vector<int>> dp(n, vector<int>(26, 0));
        dp[0][s[0] - 'a']++;
        for(int i=1; i<n; i++)
        {
            // copy the freq vector of prev char 
            // into the freq vector of curr char
            for(int j=0; j<26; j++)
                dp[i][j] = dp[i-1][j];
            
            // increment the freq of curr char
            dp[i][s[i] - 'a']++;
        }

        vector<bool> ans;
        for(vector<int>& query: queries)
        {
            int left = query[0];
            int right = query[1];
            int ops = query[2]; // max operations allowed

            int oddFreqCount = (right - left + 1) % 2 == 1 ? -1 : 0;
            for(int j=0; j<26; j++)
            {
                int l = left - 1 >= 0 ? dp[left - 1][j] : 0;
                int r = dp[right][j];
                
                if((r - l) % 2 == 1)
                    oddFreqCount++;
            }
            
            // 'oddFreqCount' is always even
            ans.push_back(oddFreqCount / 2 <= ops);
        }

        return ans;
    }
};

/*
# dp[i]: freq vector of substring in index range [0, i]

# in 1 operation we can change any char into any other char
  thus, incrementing the freq of 1 char while 
  simultaneously decrementing the freq of other
# for a substring of length n, suppose there are x even and y odd freq chars
  let freq of even nums be (E1, E2, ... Ex) 
  and that of odd nums be (O1, O2, ..., Oy)
  then, sum of freq of each char = length of substring
  (E1 + E2 + ... Ex) + (O1 + O2 + ... + Oy) = n
# (E1 + E2 + ... Ex) is basically sum of x even nums, so its even
# thus, (O1 + O2 + ... + Oy) must have the same parity as n
  # when n is even: (O1 + O2 + ... + Oy) is also even: 
    sum of y odd nums can be even only when y is even
  # when n is odd: (O1 + O2 + ... + Oy) is also odd: 
    sum of y odd nums can be odd only when y is odd
# therefore, parity of y is the same as that of n
# in the code: y is replaced with oddFreqCount
  when length of substring, n, 
  is even, oddFreqCount is initialized with 0 and
  when n is odd, oddFreqCount is initialized with -1
  thus, oddFreqCount is always even no matter the parity of n
*/