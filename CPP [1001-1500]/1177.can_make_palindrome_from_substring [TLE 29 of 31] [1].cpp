class Solution {
public:
    // T.C.=O(q*n), S.C.=O(26)
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> ans;
        for(vector<int>& query: queries)
        {
            int left = query[0];
            int right = query[1];
            int ops = query[2]; // max operations allowed

            vector<int> freq(26, 0);
            for(int i=left; i<=right; i++)
                freq[s[i] - 'a']++;
            
            int oddFreqCount = (right - left + 1) % 2 == 1 ? -1 : 0;
            for(int i=0; i<26; i++)
                if(freq[i] % 2 == 1)
                    oddFreqCount++;
            
            // 'oddFreqCount' is always even
            ans.push_back(oddFreqCount / 2 <= ops);
        }

        return ans;
    }
};

/*
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