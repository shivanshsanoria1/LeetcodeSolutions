class Solution {
public:
    // T.C.=O(n1*n2), S.C.=O(1)
    // Sliding-window (fixed-length)
    int strStr(string haystack, string needle) { 
        int n1=haystack.length(), n2=needle.length();
        // s2 cannot not be longer than s1
        if(n1 < n2) 
            return -1;

        for(int start = 0; start <= n1-n2; start++)
        {
            int i = start, j = 0;
            while(j < n2)
            {
                if(haystack[i] != needle[j])
                    break;
                i++;
                j++;
            }

            if(j == n2)
                return start;
        }

        // s2 not found in s1
        return -1;
    }
};
// s1: haystack, s2: needle