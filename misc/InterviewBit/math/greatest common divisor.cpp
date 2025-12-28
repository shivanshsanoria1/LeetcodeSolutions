int Solution::gcd(int A, int B) {
    if(A==0)
        return B;
    if(B==0)
        return A;
    if(A==1 || B==1)
        return 1;
    while(A != B)
    {
        if(A>=B)
            A-=B;
        else
            B-=A;
    }
    return A;
}
