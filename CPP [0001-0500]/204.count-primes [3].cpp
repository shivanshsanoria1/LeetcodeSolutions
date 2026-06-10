class Solution {
public:
    int countPrimes(int n) { //count primes upto n (i.e. not including n); Sieve of Eratosthenes algo., T.C.=O(nloglogn), S.C=O(n)
        if(n < 2) //no primes for n=0 and n=1
            return 0;
        vector<bool> primes(n,true); //assume all nums upto n are prime
        primes[0]=false; //0 is not prime
        primes[1]=false; //1 is not prime
        for(int i=2; i*i<n; i++) //i<sqrt(n), '<=' sign is not used as n is not to be included 
            if(primes[i]==true) //found a prime
                for(int j=i*i; j<n; j=j+i) //mark all multiples of that prime upto n as false
                    primes[j]=false;
        int c=0;
        for(int i=2; i<n; i++) //count the primes from 2 upto n
            if(primes[i]==true)
                c++;
        return c;
    }
};