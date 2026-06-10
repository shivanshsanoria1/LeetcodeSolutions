class Solution {
public:
    string reverseStr(string s, int k) {
        bool rev = true; // represents whether chars in curr block should be reversed or not
        string ans = "";
        for(int i=0; i<s.length(); i += k)
        {
            string temp = s.substr(i, k);
            if(rev)
                reverse(temp.begin(), temp.end());
            ans += temp;
            rev = !rev;
        }
        return ans;
    }
};
/*
# for every block of k chars- k1, k2, k3, k4, ...
# reverse the chars in block k1, k3, k5, ...
# don't reverse the chars in block k2, k4, k6, ...
# the last block may have less than k chars
*/