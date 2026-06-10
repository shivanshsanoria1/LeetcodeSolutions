class Solution {
public:
    int countBinarySubstrings(string s) { // T.C.=O(n^2), S.C.=O(1)
        int n=s.length();
        int count = 0;
        for(int i=0; i<n; i++)
        {
            int c0 = s[i] == '0' ? 1 : 0;
            int c1 = s[i] == '1' ? 1 : 0;
            int changes = 0; // counts the number of changes from 0 to 1 or 1 to 0
            for(int j=i+1; j<n; j++)
            {
                if(s[j] == '0')
                    c0++;
                else
                    c1++;
                // found a change from 0 to 1 or 1 to 0
                if(s[j-1] != s[j])
                    changes++;
                // no more valid substrings can be formed starting at index i 
                if(changes > 1) 
                    break;
                // found valid substring
                if(c0 == c1 && changes == 1)
                    count++;
            }
        }
        return count;
    }
};