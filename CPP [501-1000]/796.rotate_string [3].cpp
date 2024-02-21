class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) // both strings must be of same length
            return false;
        if(s == goal)
            return true;
        int n = s.length();
        string s2 = s + s;
        // check if 'goal' is a subtring if 's2'
        for(int i=0; i<2*n; i++)
            if(s2.substr(i, n) == goal)
                return true;
        return false;
    }
};