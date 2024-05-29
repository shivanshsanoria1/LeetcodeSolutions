class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        int maxLen = 0;

        for(int i=0; i<n; i++)
        {
            int cost = 0;
            for(int j=i; j<n; j++)
            {
                cost += abs(s[j] - t[j]);

                if(cost <= maxCost)
                    maxLen = max(maxLen, j-i+1);
                else
                    break;
            }
        }

        return maxLen;
    }
};