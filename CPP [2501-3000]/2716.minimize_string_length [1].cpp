class Solution {
public:
    int minimizedStringLength(string s) {
        vector<bool> found(26, false);
        for(char ch: s)
            found[ch - 'a'] = true;
        
        int count = 0;
        for(int i=0; i<26; i++)
            if(found[i])
                count++;
        return count;
    }
};
// just count the distinct chars in the string