class Solution {
public:
    bool hasMatch(string s, string p) {
        int idx = p.find("*");
        string p1 = p.substr(0, idx);
        string p2 = p.substr(idx + 1);

        // index of first occurence of p1 in s
        int start1 = s.find(p1);
        if(start1 == -1)
            return false;
        // index of last occurence of p2 in s
        int start2 = s.rfind(p2);
        if(start2 == -1)
            return false;

        return start1 + p1.length() <= start2;
    }
};