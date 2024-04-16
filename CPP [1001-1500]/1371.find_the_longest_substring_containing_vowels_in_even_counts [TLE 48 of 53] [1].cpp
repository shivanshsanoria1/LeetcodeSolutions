class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int findTheLongestSubstring(string s) {
        int n=s.length();
        int maxLen = 0;

        for(int j=0; j<n; j++)
        {
            int a = 0, e = 0, i = 0, o = 0, u = 0;

            for(int k=j; k<n; k++)
            {
                if(s[k] == 'a')
                    a++;
                else if(s[k] == 'e')
                    e++;
                else if(s[k] == 'i')
                    i++;
                else if(s[k] == 'o')
                    o++;
                else if(s[k] == 'u')
                    u++;
                
                if(a % 2 == 0 && e % 2 == 0 && i % 2 == 0 && o % 2 == 0 && u % 2 == 0)
                    maxLen = max(maxLen, k-j+1);
            }
        }

        return maxLen;
    }
};