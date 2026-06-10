class Solution {
public:
    // T.C.=O(n*m), S.C.=O(1)
    // n: size of words[], m: length of pref
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(string& word: words)
            if(word.find(pref) == 0)
                count++;

        return count;
    }
};