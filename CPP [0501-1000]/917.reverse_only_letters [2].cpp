class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.length(), left=0, right=n-1;
        char temp;
        while(left<right)
        {
            if(isalpha(s[left]) && isalpha(s[right]))
            {
                temp=s[left];
                s[left]=s[right];
                s[right]=temp;
                left++;
                right--;
            }
            else
            {
                if(!isalpha(s[left]))
                    left++;
                if(!isalpha(s[right]))
                    right--;
            }
        }
        return s;
    }
};