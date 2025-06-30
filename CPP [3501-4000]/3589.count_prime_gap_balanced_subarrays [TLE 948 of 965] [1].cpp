class Solution {
private:
    bool isPrime(int num){
        if(num <= 1)
            return false;
        if(num == 2)
            return true;
        if(num % 2 == 0)
            return false;

        for(int i=3; i*i<=num; i+=2)
            if(num % i == 0)
                return false;
        
        return true;
    }

public:
    // T.C.=O(n*sqrt(m) + n^2), S.C.=O(n)
    // m: max-val in nums[]
    int primeSubarray(vector<int>& nums, int k) {
        unordered_set<int> primes;
        for(int num: nums)
            if(isPrime(num))
                primes.insert(num);
        
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++)
        {
            int primeCount = 0;
            int maxPrime = 0, minPrime = int(1e9);
            for(int j=i; j<n; j++)
            {
                if(primes.find(nums[j]) != primes.end())
                {
                    primeCount++;
                    maxPrime = max(maxPrime, nums[j]);
                    minPrime = min(minPrime, nums[j]);

                    if(maxPrime - minPrime > k)
                        break;
                }
                
                if(primeCount >= 2)
                    count++;
            }
        }

        return count;
    }
};