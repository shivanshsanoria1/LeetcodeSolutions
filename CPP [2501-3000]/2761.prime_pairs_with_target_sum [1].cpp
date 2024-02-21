class Solution {
public:
    void sieveOfEratosthenes(vector<bool>& isPrime, vector<int>& primes){
        int n = isPrime.size() - 1;
        for(int i=2; i*i <= n; i++)
        {
            if(!isPrime[i])
                continue;
            for(int j=i*i; j<=n; j += i)
                isPrime[j] = false;
        }

        for(int i=2; i<=n; i++)
            if(isPrime[i])
                primes.push_back(i);
    }

    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> isPrime(n+1, true);
        vector<int> primes;
        sieveOfEratosthenes(isPrime, primes);
        vector<vector<int>> ans;
        int left = 0, right = primes.size()-1;
        while(left <= right)
        {
            if(primes[left] + primes[right] == n)
            {
                ans.push_back({primes[left], primes[right]});
                left++;
                right--;
            }
            else if(primes[left] + primes[right] < n)
                left++;
            else
                right--;
        }
        return ans;
    }
};