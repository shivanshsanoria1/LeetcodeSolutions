class Solution {
public:
    // T.C.=O(n1 + n2), S.C.=O(1)
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.length(), n2 = str2.length();

        if(n1 < n2)
            return false;
        
        int i=0, j=0;
        while(i < n1 && j < n2)
        {
            if(str1[i] == str2[j] || ((str2[j] - str1[i]) + 26) % 26 <= 1)
                j++;
            i++;
        }

        return j == n2;
    }
};