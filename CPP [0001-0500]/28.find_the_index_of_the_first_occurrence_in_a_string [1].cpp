class Solution {
public:
    // T.C.=O(n1 * n2), S.C.=O(1)
    // Sliding-window (fixed-length)
    int strStr(string haystack, string needle) { 
        // rename the parameters
        const string& s1 = haystack;
        const string& s2 = needle;

        const int n1 = s1.length(), n2 = s2.length();
        // s2 cannot not be longer than s1
        if(n1 < n2) 
            return -1;

        for(int start = 0; start <= n1-n2; start++){
            int j = 0;
            for(int i = start; j < n2 && s1[i] == s2[j]; i++, j++){}

            if(j == n2)
                return start;
        }

        // s2 not found in s1
        return -1;
    }
};