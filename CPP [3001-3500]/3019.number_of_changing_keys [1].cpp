class Solution {
public:
    int countKeyChanges(string s) {
        int count = 0;
        for(int i=1; i<s.length(); i++)
            if(abs(s[i-1] - s[i]) != 32 && s[i-1] != s[i])
                count++;
        return count;
    }
};