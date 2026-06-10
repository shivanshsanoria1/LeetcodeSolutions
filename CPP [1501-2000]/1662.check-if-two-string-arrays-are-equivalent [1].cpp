class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "", s2 = "";
        for(string& str: word1)
            for(char ch: str)
                s1 += ch;
        for(string& str: word2)
            for(char ch: str)
                s2 += ch;
        if(s1.length() != s2.length())
            return false;
        for(int i=0; i<s1.length(); i++)
            if(s1[i] != s2[i])
                return false;
        return true;
    }
};
// T.C.=O(n*k), S.C.=O(n*k)
// n: num of strings, k: max length of a string