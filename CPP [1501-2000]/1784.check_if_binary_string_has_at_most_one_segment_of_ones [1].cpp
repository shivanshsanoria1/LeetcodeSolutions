class Solution {
public:
    bool checkOnesSegment(string s) {
        int flips = 0;
        for(int i=1; i<s.length(); i++)
        {
            if(s[i] != s[i-1])
                flips++;
            if(flips > 1)
                return false;
        }
        return true;
    }
};