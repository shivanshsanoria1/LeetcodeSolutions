class Solution {
public:
    // T.C.=O(), S.C.=O(1)
    // 2-pointer
    int appendCharacters(string s, string t) {
        int j = 0;
        for(int i=0; i < s.length() && j < t.length(); i++)
            if(s[i] == t[j])
                j++;
        return t.length() - j;
    }
};