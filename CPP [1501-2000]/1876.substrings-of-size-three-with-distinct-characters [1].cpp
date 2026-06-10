class Solution {
public:
    int countGoodSubstrings(string s) {
        int left = 0, right = 2;
        int count = 0;
        while(right < s.length())
        {
            if(s[left] != s[left + 1] && s[left + 1] != s[right] && s[right] != s[left])
                count++;
            left++;
            right++;
        }
        return count;
    }
};