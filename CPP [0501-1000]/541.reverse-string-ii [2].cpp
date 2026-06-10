class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0; i<s.length(); i += 2*k)
        {
            if(i + k <= s.length())
                reverse(s.begin() + i, s.begin() + i + k);
            else
                reverse(s.begin() + i, s.end());
        }
        return s;
    }
};
/*
# for every block of k chars- k1, k2, k3, k4, ...
# reverse the chars in block k1, k3, k5, ...
# don't reverse the chars in block k2, k4, k6, ...
# the last block may have less than k chars
*/