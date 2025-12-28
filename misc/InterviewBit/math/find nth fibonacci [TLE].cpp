int Solution::solve(int n) {
    if(n<=2)
        return 1;
    int f2=1, f1=1, f;
    for(int i=3; i<=n; i++)
    {
        f=(f1+f2)%(1000000007);
        f2=f1;
        f1=f;
    }
    return f;
}
