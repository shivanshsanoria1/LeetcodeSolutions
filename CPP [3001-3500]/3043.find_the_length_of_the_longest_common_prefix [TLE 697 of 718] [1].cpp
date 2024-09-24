class Solution {
private:
    // returns the length of the Longest-Common-Prefix (LCP)
    // of nums num1 and num2
    int findLengthOfLCP(int num1, int num2){
        string s1 = to_string(num1);
        string s2 = to_string(num2);

        int n1 = s1.length();
        int n2 = s2.length();

        for(int i=0; i<min(n1, n2); i++)
            if(s1[i] != s2[i])
                return i;
        
        return min(n1, n2);
    }

public:
    // T.C.=O(n1*n2*d), S.C.=O(1)
    // d: max count of digits in a num (limited to 9 here)
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int lcp = 0;
        for(int num1: arr1)
            for(int num2: arr2)
                lcp = max(lcp, findLengthOfLCP(num1, num2));
        
        return lcp;
    }
};