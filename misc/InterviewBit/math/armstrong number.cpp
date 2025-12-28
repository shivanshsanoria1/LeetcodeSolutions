int Solution::solve(int n) {
    int num=n, sum=0, c=0;
    while(num > 0)
    {
        c++;
        num/=10;
    }
    num=n;
    while(num > 0)
    {
        sum+= pow(num%10,c);
        num/=10;
    }
    return sum==n ? true : false;
}
