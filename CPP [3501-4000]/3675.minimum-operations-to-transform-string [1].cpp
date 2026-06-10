class Solution {
public:
    // T.C.=O(n + 26), S.C.=O(26)
    int minOperations(string s) {
        vector<bool> isPresent(26, false);
        for(char ch: s)
            isPresent[ch - 'a'] = true;

        for(int i=1; i<26; i++)
            if(isPresent[i])
                return 26 - i;

        return 0;
    }
};