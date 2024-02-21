class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) { // T.C.=O(n), S.C.=O(26)
        int n=s.length();
        // to store the index of earliest occurence of each char in string
        vector<int> indexes(26, -1); 
        int ans = -1;
        for(int i=0; i<n; i++)
        {
            if(indexes[s[i] - 'a'] == -1) // s[i] not found in indexes vector
                indexes[s[i] - 'a'] = i;
            else // find the length of substring between curr s[i] and its earliest occurence
                ans = max(ans, i-indexes[s[i] - 'a']-1);
        }
        return ans;
    }
};