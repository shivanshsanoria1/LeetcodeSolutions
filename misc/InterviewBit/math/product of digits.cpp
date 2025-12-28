int Solution::solve(int n) {
    if(n==0)
        return 0;
    int pro=1;
    while(n > 0)
    {
        pro*= n%10;
        n/=10;
    }
    return pro;
}
