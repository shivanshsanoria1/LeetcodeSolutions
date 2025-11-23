class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(int i=0; i<s.length(); i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
                str += s[i];
            else if(s[i]>='A' && s[i]<='Z') 
                str += s[i]+32; //convert uppercase to lowercase
        }
        for(int i=0,j=str.length()-1; i<j; i++,j--) //check if str is palindrome
            if(str[i] != str[j])
                return false;
        return true;
    }
};