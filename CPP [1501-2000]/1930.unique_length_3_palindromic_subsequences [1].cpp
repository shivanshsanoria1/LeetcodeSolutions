class Solution {
public:
    // T.C.=O(26*n), S.C.=O(26)
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        // index of the first occurence of a char
        vector<int> firstIdx(26, -1);
        // index of the last occurence of a char
        vector<int> lastIdx(26, -1);

        int uniqueChars = 0;
        for(int i=0; i<n && uniqueChars < 26; i++)
            if(firstIdx[s[i] - 'a'] == -1)
            {
                firstIdx[s[i] - 'a'] = i;
                uniqueChars++;
            }
        
        uniqueChars = 0;
        for(int i=n-1; i>=0 && uniqueChars < 26; i--)
            if(lastIdx[s[i] - 'a'] == -1)
            {
                lastIdx[s[i] - 'a'] = i;
                uniqueChars++;
            }
        
        int count = 0;

        for(int i=0; i<26; i++)
        {
            if(firstIdx[i] == lastIdx[i])
                continue;

            // find the num of unique chars in index-range 
            // (firstIdx[i], lastIdx[i]), both exclusive
            vector<bool> visited(26, false);
            int uniqueChars = 0;

            for(int j = firstIdx[i] + 1; j < lastIdx[i] && uniqueChars < 26; j++)
                if(!visited[s[j] - 'a'])
                {
                    visited[s[j] - 'a'] = true;
                    uniqueChars++;
                }

            count += uniqueChars;
        }

        return count;
    }
};
/*
# the idea is to generate length-3 palindromes of the form: 
  "a$a", "b$b", "c$c", ..., "z$z"; where '$' can be any char from [a, z]
# find the index of first and last occurence each char in string 's'
# find the number of unique chars in index-range (first, last), both exclusive,
  for each palindrome 
*/