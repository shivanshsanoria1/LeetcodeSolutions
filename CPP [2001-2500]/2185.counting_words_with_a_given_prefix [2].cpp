class Solution {
public:
    // T.C.=O(n*m), S.C.=O(m)
    // n: size of words[], m: length of pref
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(string& word: words)
            if(word.substr(0, pref.length()) == pref)
                count++;

        return count;
    }
};