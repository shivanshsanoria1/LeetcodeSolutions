class Solution {
public:
    bool isPalindrome(string& s, int i, int j) //checks if string formed from index i to j is palindrome or not
    {
        while(i < j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        for(int i=0,j=s.length()-1; i<j; i++,j--)
            if(s[i] != s[j])
                return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
        return true;
    }
};