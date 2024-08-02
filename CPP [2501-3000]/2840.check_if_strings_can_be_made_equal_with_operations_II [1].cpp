class Solution {
private:
    string getHash(string& s){
        string even = "";
        string odd = "";

        for(int i=0; i<s.length(); i++)
        {
            if(i % 2 == 0)
                even += s[i];
            else
                odd += s[i];
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        return even + odd;
    }

public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    bool checkStrings(string s1, string s2) {
        return getHash(s1) == getHash(s2);
    }
};