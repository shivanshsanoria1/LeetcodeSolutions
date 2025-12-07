class Solution {
private:
    typedef long long int lli;

    // returns prime nums in range [1, n]
    vector<int> sieveOfEratosthenes(int n){
        if(n < 0)
            return {};
        
        // initially assume all nums are prime
        vector<int> isPrime(n + 1, true);
        // 0 and 1 are not prime
        isPrime[0] = false;
        isPrime[1] = false;
        
        // for every prime num 'i' mark all its 
        // multiples (starting from i^2) as not-prime
        for(int i=2; i<=n; i++)
            if(isPrime[i])
                for(lli m = (lli)i*i; m<=n; m += i)
                    isPrime[m] = false;
        
        vector<int> primes;
        for(int i=2; i<=n; i++)
            if(isPrime[i])
                primes.push_back(i);
        
        return primes;
    }

public:
    // T.C.=O(), S.C.=O(n)
    int largestPrime(int n) {
        vector<int> primes = sieveOfEratosthenes(n);

        unordered_set<int> primeSet(primes.begin(), primes.end());

        lli prefixSum = 0;
        int maxPrime = 0;
        for(int i=0; i<primes.size() && prefixSum <= primes.back(); i++){
            prefixSum += primes[i];
            if(primeSet.find(prefixSum) != primeSet.end())
                maxPrime = prefixSum;
        }

        return maxPrime;
    }
};