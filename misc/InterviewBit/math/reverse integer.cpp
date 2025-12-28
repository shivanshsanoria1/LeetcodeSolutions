int Solution::reverse(int n) {
    long int num= abs(n);
    long int rev=0;
    while(num > 0)
    {
        rev= rev*10 + num%10;
        num/=10;
    }
    if(rev > INT_MAX || rev-1 > INT_MAX)
        return 0;
    return n>=0 ? rev : -rev;
}
