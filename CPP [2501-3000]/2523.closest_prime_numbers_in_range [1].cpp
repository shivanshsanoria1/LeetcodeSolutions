class Solution {
private:
    vector<int> sieveOfEratosthenes(int left, int right){
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(int p=2; p*p <= right; p++)
            if(isPrime[p])
                for(int m = p*p; m <= right; m += p)
                    isPrime[m] = false;
        
        vector<int> primes;

        for(int i=left; i<=right; i++)
            if(isPrime[i])
                primes.push_back(i);
        
        return primes;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = sieveOfEratosthenes(left, right);

        vector<int> ans = {-1, -1};

        if(primes.size() < 2)
            return ans;
        
        int minDiff = INT_MAX;
        for(int i=1; i<primes.size() && minDiff > 2; i++)
            if(primes[i] - primes[i-1] < minDiff)
            {
                minDiff = primes[i] - primes[i-1];
                ans[0] = primes[i-1];
                ans[1] = primes[i];
            }

        return ans;
    }
};
// min diff between 2 distinct primes is 2
// except the case of primes {2, 3}