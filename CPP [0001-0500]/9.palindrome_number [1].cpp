class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else if(x==0)
            return true;
        else
        {
            int digit,n=x;
            long int rev=0;
            do{
                digit = n%10;
                rev = (rev*10) + digit;
                n=n/10;
            }while(n!=0);
            if(rev==x)
                return true;
            return false;
        }
    }
};