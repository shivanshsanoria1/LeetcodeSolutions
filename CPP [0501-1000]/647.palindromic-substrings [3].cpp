class Solution {
private:
    int countPalindrome(string& s, int left, int right){
        int count = 0;
        while(left >= 0 && right < s.length())
        {
            if(s[left] != s[right])
                break;
            count++;
            left--;
            right++;
        }
        return count;
    }

public:
    // T.C=O(n^2), S.C.=O(1)
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0; i<s.length(); i++)
        {
            int evenCount = countPalindrome(s, i, i+1);
            int oddCount = countPalindrome(s, i, i);
            count += evenCount + oddCount;
        }
        return count;
    }
};

/*
# to check if a string is palindrome or not, take 2 pointers 'left' and 'right'
  and expand the 'left' in the left direction and 'right' in the right direction,
  thus expanding the window size
# if at any point s[left] and s[right] don't match then stop expanding the window
# to generate even length substrings start with 'left' and 'right' at adjacent indexes,
  ie, 'left' at i and 'right' at i+1
# to generate odd length substrings start with 'left' and 'right' at the same index,
  ie, 'left' at i and 'right' at i
# evenCount: count of palindrome substrings of even length with middle chars at index i and i+1
# oddCount: count of palindrome substrings of odd length with middle char at index i
*/