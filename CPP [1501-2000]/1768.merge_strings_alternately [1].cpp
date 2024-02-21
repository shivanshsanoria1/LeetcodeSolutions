class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n1=word1.length(), n2=word2.length();
        int i=0, j=0;
        while(i < n1 && j < n2) // both strings are non empty
        {
            ans = ans + word1[i] + word2[j];
            i++;
            j++;
        }
        while(i < n1) // chars are remaining in string1
        {
            ans += word1[i];
            i++;
        }
        while(j < n2) // chars are remaining in string2
        {
            ans += word2[j];
            j++;
        }
        return ans;
    }
};