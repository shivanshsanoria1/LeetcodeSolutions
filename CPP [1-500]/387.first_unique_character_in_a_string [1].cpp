class Solution {
public:
    // T.C.=O(n), S.C.=O(26)
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch - 'a']++;
        // first non-repeating char must have a freq of 1
        for(int i=0; i<s.length(); i++)
            if(freq[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};