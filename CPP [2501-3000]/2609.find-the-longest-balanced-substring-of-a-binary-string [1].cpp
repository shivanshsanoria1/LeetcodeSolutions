class Solution {
public:
    int findTheLongestBalancedSubstring(string s) { // T.C.=O(n^2), S.C.=O(1)
        int n=s.length();
        int ans = 0;
        for(int i=1; i<n; i++)
            if(s[i-1] == '0' && s[i] == '1')
            {
                int left = i-1, right = i;
                while(left >= 0 && right < n)
                {
                    if(s[left] == '1' || s[right] == '0')
                        break;
                    ans = max(ans, right - left + 1);
                    left--;
                    right++;
                }
            }
        return ans;
    }
};