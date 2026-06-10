class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n1=s1.length(), n2=s2.length(), n3=s3.length();
        int minLen = min(n1, min(n2, n3));
        int idx = -1;
        for(int i=0; i<minLen; i++)
        {
            if(s1[i] == s2[i] && s2[i] == s3[i])
                idx = i;
            else
                break;
        }
        return idx == -1 ? -1 : max(n1-idx-1, 0) + max(n2-idx-1, 0) + max(n3-idx-1, 0);
    }
};