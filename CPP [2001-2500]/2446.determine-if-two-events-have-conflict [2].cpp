class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string s1 = event1[0], e1 = event1[1];
        string s2 = event2[0], e2 = event2[1];
        return (s2 >= s1 && s2 <= e1) || (s1 >= s2 && s1 <= e2) ? true : false;
    }
};