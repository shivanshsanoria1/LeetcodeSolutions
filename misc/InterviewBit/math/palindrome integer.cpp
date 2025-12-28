int Solution::isPalindrome(int n) {
    int num=n, rev=0;
    while(num > 0)
    {
        rev= rev*10 + num%10;
        num/=10;
    }
    return n==rev ? true : false; 
}
