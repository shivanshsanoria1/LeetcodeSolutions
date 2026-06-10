class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int s1 = 60*(10*(event1[0][0]-'0') + (event1[0][1]-'0')) + 10*(event1[0][3]-'0') + (event1[0][4]-'0');
        int e1 = 60*(10*(event1[1][0]-'0') + (event1[1][1]-'0')) + 10*(event1[1][3]-'0') + (event1[1][4]-'0');
        int s2 = 60*(10*(event2[0][0]-'0') + (event2[0][1]-'0')) + 10*(event2[0][3]-'0') + (event2[0][4]-'0');
        int e2 = 60*(10*(event2[1][0]-'0') + (event2[1][1]-'0')) + 10*(event2[1][3]-'0') + (event2[1][4]-'0');
        return (s2 >= s1 && s2 <= e1) || (s1 >= s2 && s1 <= e2) ? true : false;
    }
};