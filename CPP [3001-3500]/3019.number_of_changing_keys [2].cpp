class Solution {
public:
    int countKeyChanges(string s) {
        int count = 0;
        for(int i=1; i<s.length(); i++)
            if(tolower(s[i-1]) != tolower(s[i]))
                count++;
        return count;
    }
};