class Solution {
public:
    // T.C.=O(26 + n), S.C.=O(26 + n)
    int uniqueLetterString(string s) {
        int n=s.length();
        vector<vector<int>> charIndexes(26);
        for(int i=0; i<n; i++)
            charIndexes[s[i] - 'A'].push_back(i);
        
        int totalCount = 0;
        for(char ch='A'; ch<='Z'; ch++)
        {
            vector<int>& indexes = charIndexes[ch - 'A'];

            for(int i=0; i<indexes.size(); i++)
            {
                int prevIdx = i-1 >= 0 ? indexes[i-1] : -1;
                int nextIdx = i+1 < indexes.size() ? indexes[i+1] : n;

                int left = indexes[i] - prevIdx - 1;
                int right = nextIdx - indexes[i] - 1;

                // num of substrings of s having unique char s[indexes[i]]
                totalCount += left + right + left*right + 1;
            }
        }

        return totalCount;
    }
};