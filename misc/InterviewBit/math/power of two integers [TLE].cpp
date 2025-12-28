int Solution::isPower(int n) {
    if(n==1)
        return true;
    for(int i=2; i*i<=n; i++)
    {
        int p=i;
        while(p<n)
            p=p*i;
        if(p==n)
            return true;
    }
    return false;
}
