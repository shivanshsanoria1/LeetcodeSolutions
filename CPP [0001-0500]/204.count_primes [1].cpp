class Solution {
public:
    int countPrimes(int n) { // count primes upto n (i.e. not including n)
        vector<bool> primes(n+1,true); // array of size n with all elements as true
        if(n>=0)
            primes[0]=false; // 0 is not prime
        if(n>=1)
            primes[1]=false; // 1 is not prime
        for(int i=2; i<=n/2; i++)
            for(int j=2*i; j<n; j=j+i) // mark all multiples of i as false
                primes[j]=false;
        int c=0;
        for(int i=2; i<n; i++)
            if(primes[i]==true)
                c++;
        return c;
    }
};