class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.length(), left=0, right=n-1;
        char temp;
        while(left<right)
        {
            if(isValid(s[left])==true && isValid(s[right])==true)
            {
                temp=s[left];
                s[left]=s[right];
                s[right]=temp;
                left++;
                right--;
            }
            else
            {
                if(isValid(s[left])==false)
                    left++;
                if(isValid(s[right])==false)
                    right--;
            }
        }
        return s;
    }
    
    bool isValid(char ch)
    {
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
            return true;
        return false;
    }
};