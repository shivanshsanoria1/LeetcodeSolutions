class Solution {
public:
    bool isPrime(int n)
    {
        if(n<=1)
            return false;
        if(n==2) //2 is prime
            return true;
        if(n%2==0) //even num except 2 are not prime
            return false;
        for(int i=3; i*i<=n; i=i+2) //n is odd, check if 3,5,7,9,...,sqrt(n) divide n or not
            if(n%i==0)
                return false;
        return true;
    }
    
    bool isThree(int n) { // n has 3 factors if n is a perfect square and sqrt(n) is a prime
        int sq_root=sqrt(n);
        if(sq_root*sq_root!=n) //n is not a perfect square
            return false;
        return isPrime(sq_root);
    }
};