int Solution::solve(int A) {
    int target= abs(A); //convert any -ive num to +ive
    int n= ceil((-1.0 + sqrt(1 + 8.0*target))/2);
    int sum= (n*(n + 1))/2;
    if (sum == target)
        return n;
    int diff= sum - target;
    if (diff%2 == 0) //diff is even
        return n;
    else //diff is odd
    {
        if(n%2 == 0) //n is even
            return n+1;
        else //n is odd
            return n+2;
    }
}