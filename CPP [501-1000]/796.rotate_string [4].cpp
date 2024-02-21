class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) // both strings must be of same length
            return false;
        if(s == goal)
            return true;
        string s2 = s + s;
        // check if 'goal' is a subtring if 's2'
        return s2.find(goal) != string::npos ? true : false;
    }
};