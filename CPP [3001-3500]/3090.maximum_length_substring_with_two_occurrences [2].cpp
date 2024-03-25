class Solution {
public:
    // T.C.=O(n), S.C.=O(26)
    // Sliding-window
    int maximumLengthSubstring(string s) {
        int left = 0, right = 0;
        vector<int> freq(26, 0);
        int maxLen = 0;

        while(right < s.length())
        {
            freq[s[right] - 'a']++;

            // decrease the window until it becomes valid
            while(freq[s[right] - 'a'] > 2)
            {
                freq[s[left] - 'a']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};