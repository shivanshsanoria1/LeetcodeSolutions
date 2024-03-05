class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minimumLength(string s) {
        int left = 0, right = s.length()-1;
        while(left < right && s[left] == s[right])
        {
            char ch = s[left];
            
            while(left < s.length() && s[left] == ch)
                left++;
            while(right >= 0 && s[right] == ch)
                right--;

            if(left == right)
                return 1;
            if(left > right)
                return 0;
        }
        return right - left + 1;
    }
};