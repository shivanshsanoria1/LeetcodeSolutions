class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int countKConstraintSubstrings(string s, int k) {
        int n=s.length();
        int count = 0;

        for(int i=0; i<n; i++)
        {
            int count0 = 0, count1 = 0;
            for(int j=i; j<n; j++)
            {
                if(s[j] == '0')
                    count0++;
                else // s[j] == '1'
                    count1++;

                if(count0 <= k || count1 <= k)
                    count++;
                else
                    break;
            }
        }

        return count;
    }
};