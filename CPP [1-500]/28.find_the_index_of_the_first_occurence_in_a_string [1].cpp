class Solution {
public:
    int strStr(string haystack, string needle) { //T.C.=O(m*n)
        int n1= haystack.length(), n2=needle.length();
        if(n1 < n2) //string2 should not be longer than string1
            return -1;
        for(int start=0; start <= n1-n2; start++)
        {
            int i=start, j=0;
            while(j < n2)
            {
                if(haystack[i] != needle[j])
                    break;
                i++;
                j++;
            }
            if(j==n2)
                return start;
        }
        return -1;
    }
};