class Solution {
public:
    int countBinarySubstrings(string s) { // T.C.=O(n^2), S.C.=O(1)
        int n=s.length();
        int count = 0;
        for(int i=1; i<n; i++)
        {
            if(s[i-1] == s[i])
                continue;
            int left = i-1, right = i;
            while(left >=0 && right < n)
            {
                if(s[left] == s[i-1] && s[right] == s[i])
                    count++;
                else
                    break;
                left--;
                right++;
            }
        }
        return count;
    }
};