class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // sliding-window
    bool hasSpecialSubstring(string s, int k) {
        int n = s.length();
        int left = 0, right = 0;

        while(right < n)
        {
            // window is no longer valid so reset 'left'
            if(s[left] != s[right])
                left = right;
            // window size reached k
            else if(right - left + 1 == k)
            {
                // char just to the left of window
                char left1 = left - 1 >= 0 ? s[left - 1] : '#';
                // char just to the right of window
                char right1 = right + 1 < n ? s[right + 1] : '#';

                // window is valid
                if(left1 != s[left] && s[right] != right1)
                    return true;
                // shrink the window
                else
                    left++;
            }

            // expand the window
            right++;
        }

        return false;
    }
};

// a window is valid if it contains only 1 unique char