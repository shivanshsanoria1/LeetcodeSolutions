class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    int minLength(string s) {
        while(s.find("AB") != string::npos || s.find("CD") != string::npos)
        {
            int idx = s.find("AB");
            if(idx != string::npos)
                s = s.substr(0, idx) + s.substr(idx + 2);

            idx = s.find("CD");
            if(idx != string::npos)
                s = s.substr(0, idx) + s.substr(idx + 2);
        }

        return s.length();
    }
};