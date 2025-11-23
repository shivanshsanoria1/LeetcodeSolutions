class Solution {
public:
    // returns true if s2 is a subsequence of s1
    bool isSubsequence(string& s1, string& s2){
        int n1=s1.length(), n2=s2.length();
        if(n1 < n2) // s1 cannot be smaller than s2
            return false;
        int i = 0, j = 0;
        while(i < n1 && j < n2)
        {
            if(s1[i] == s2[j])
                j++;
            i++;
        }
        return j == n2 ? true : false;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for(string& word: words)
            if(isSubsequence(s, word))
                count++;
        return count;
    }
};