class Solution {
public:
    int countBinarySubstrings(string s) { // T.C.=O(n), S.C.=O(1)
        int prevCount = 0, currCount = 1;
        int ans = 0;
        for(int i=1; i<s.length(); i++)
        {
            if(s[i-1] != s[i])
            {
                ans += min(prevCount, currCount);
                prevCount = currCount;
                currCount = 1;
            }
            else
                currCount++;
        }
        ans += min(prevCount, currCount);
        return ans;
    }
};