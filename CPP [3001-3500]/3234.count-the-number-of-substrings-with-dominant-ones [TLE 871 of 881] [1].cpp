class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int numberOfSubstrings(string s) {
        int n=s.length();
        int count = 0;

        for(int i=0; i<n; i++)
        {
            int ones = 0, zeros = 0;
            for(int j=i; j<n; j++)
            {
                if(s[j] == '1')
                    ones++;
                else
                    zeros++;
                
                if(ones >= zeros*zeros)
                    count++;
            }
        }

        return count;
    }
};