int Solution::trailingZeroes(int n) {
    int c=0, mul=5;
    while(mul<=n)
    {
        c+=n/mul;
        mul*=5;
    }
    return c;
}
