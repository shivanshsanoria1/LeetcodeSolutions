class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Sliding-window
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, right = 0;
        int cost = 0;
        int maxLen = 0;

        while(right < s.length())
        {
            cost += abs(s[right] - t[right]);

            while(cost > maxCost)
            {
                cost -= abs(s[left] - t[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};