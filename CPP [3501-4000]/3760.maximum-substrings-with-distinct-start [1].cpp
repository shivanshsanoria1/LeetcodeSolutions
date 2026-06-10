class Solution {
public:
    // T.C.=O(n + 26), S.C.=O(26)
    int maxDistinct(string s) {
        vector<bool> isPresent(26, false);
        for(char ch: s)
            isPresent[ch - 'a'] = true;
        
        return count(isPresent.begin(), isPresent.end(), true);
    }
};