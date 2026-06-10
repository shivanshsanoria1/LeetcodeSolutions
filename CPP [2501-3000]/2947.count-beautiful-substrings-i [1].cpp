class Solution {
public:
    int beautifulSubstrings(string s, int k) { // T.C.=O(n^2), S.C.=O(1)
        int n=s.length();
        int count = 0;
        for(int i=0; i<n; i++)
        {
            int countV = 0, countC = 0; // vowels and consonants count
            for(int j=i; j<n; j++)
            {
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                    countV++;
                else
                    countC++;
                if(countV == countC && (countV * countC) % k == 0)
                    count++;
            }
        }
        return count;
    }
};