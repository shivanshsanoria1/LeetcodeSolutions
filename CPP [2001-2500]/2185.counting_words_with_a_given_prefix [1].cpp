class Solution {
private:
    // returns true if s2 is a prefix of s1
    bool isPrefix(string& s1, string& s2){
        int n1 = s1.length(), n2 = s2.length();
        if(n1 < n2)
            return false;

        for(int i=0; i<n2; i++)
            if(s1[i] != s2[i])
                return false;

        return true;
    }

public:
    // T.C.=O(n*m), S.C.=O(1)
    // n: size of words[], m: length of pref
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(string& word: words)
            if(isPrefix(word, pref))
                count++;

        return count;
    }
};