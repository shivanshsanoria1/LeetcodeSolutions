class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    string reverseByType(string s) {
        // reverse the alphabets
        for(int left = 0, right = s.length()-1; left < right; ){
            // both are alpha
            if(isalpha(s[left]) && isalpha(s[right])){
                swap(s[left], s[right]);
                left++;
                right--;
            }else if(isalpha(s[left])) // only left is alpha
                right--;
            else if(isalpha(s[right])) // only right is alpha
                left++;
            else{ // both are special
                left++;
                right--;
            }
        }

        // reverse the special chars
        for(int left = 0, right = s.length()-1; left < right; ){
            // both are special
            if(!isalpha(s[left]) && !isalpha(s[right])){
                swap(s[left], s[right]);
                left++;
                right--;
            }else if(!isalpha(s[left])) // only left is special
                right--;
            else if(!isalpha(s[right])) // only right is special
                left++;
            else{ // both are alpha
                left++;
                right--;
            }
        }

        return s;
    }
};