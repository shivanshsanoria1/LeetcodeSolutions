class Solution {
public:
    // T.C.=O(26*n^2), S.C.=O(26)
    int uniqueLetterString(string s) {
        int n=s.length();
        int totalCount = 0;

        for(int i=0; i<n; i++)
        {
            vector<int> freq(26, 0);
            for(int j=i; j<n; j++)
            {
                freq[s[j] - 'A']++;

                int uniqueCount = 0;
                for(int k=0; k<26; k++)
                    if(freq[k] == 1)
                        uniqueCount++;

                totalCount += uniqueCount;
            }
        }

        return totalCount;
    }
};