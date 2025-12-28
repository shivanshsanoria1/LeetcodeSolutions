int Solution::isPower(int n) {
    if(n==1)
        return true;
    for(int i=2; i*i<=n; i++)
    {
        float p=log2(n)/log2(i);
        if(floor(p)==ceil(p))
            return true;
    }
    return false;
}
