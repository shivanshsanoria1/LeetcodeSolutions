class Solution {
private:
    // returns all prime numbers in range [1, n]
    vector<int> sieveOfEratosthenes(int n){
        vector<bool> isPrime(n+1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(int p=2; p*p <= n; p++)
            if(isPrime[p])
                for(int m = p*p; m <= n; m += p)
                    isPrime[m] = false;

        vector<int> primes;

        for(int i=2; i<=n; i++)
            if(isPrime[i])
                primes.push_back(i);
        
        return primes;
    }

public:
    // T.C.=O(m*log(logm) + n*p), S.C.=O(m)
    // m: max num in nums[], p: num of primes in range [1, m]
    int distinctPrimeFactors(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());

        vector<int> primes = sieveOfEratosthenes(maxNum);

        unordered_set<int> primeSet;

        for(int num: nums)
            for(int prime: primes)
            {
                if(prime > num)
                    break;
                if(num % prime == 0)
                    primeSet.insert(prime);
            }

        return primeSet.size();
    }
};