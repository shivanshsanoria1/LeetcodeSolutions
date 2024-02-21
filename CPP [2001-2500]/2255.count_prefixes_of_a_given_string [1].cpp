class Solution {
public:
    // returns true if s2 is a substring of s1
    bool isPrefix(string& s1, string& s2){
        if(s1.length() < s2.length()) // s1 cannot be smaller than s2
            return false;
        for(int i=0; i<s2.length(); i++)
            if(s1[i] != s2[i])
                return false;
        return true;
    }

    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for(string& word: words)
            if(isPrefix(s, word))
                count++;
        return count;
    }
};