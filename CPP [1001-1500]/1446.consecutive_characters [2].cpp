class Solution {
public:
    int maxPower(string s) { // T.C.=O(n), S.C.=O(1)
        int ans = 1;
        if(s.length() == 1)
            return ans;
        int left = 0, right = 1;
        while(right < s.length())
        {
            if(s[left] != s[right])
                left = right;
            else
                ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};