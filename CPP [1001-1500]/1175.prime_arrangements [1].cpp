class Solution {
private:
    #define MOD int(1e9 + 7)

    int sieveOfEratosthenes(int n){
        vector<bool> primes(n+1, true);
        primes[0] = false;
        primes[1] = false;

        for(int p=2; p*p <= n; p++)
            if(primes[p])
                for(int i=p*p; i<=n; i += p)
                    primes[i] = false;

        int primeCount = 0;
        for(int i=2; i<=n; i++)
            if(primes[i])
                primeCount++;
        return primeCount;
    }

    int factorial(int n){
        if(n <= 1)
            return 1;
        return ((long long int)n * factorial(n-1)) % MOD;
    }

public:
    int numPrimeArrangements(int n) {
        int primeCount = sieveOfEratosthenes(n);
        int nonPrimeCount = n - primeCount;
        return ((long long int)factorial(primeCount) * factorial(nonPrimeCount)) % MOD;
    }
};