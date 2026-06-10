class Solution {
private:
    typedef long long int lli;

    vector<int> sieveOfEratosthenes(int n){
        // initially assume all nums are prime
        vector<int> isPrime(n+1, true);
        // 0 and 1 are not prime
        isPrime[0] = false;
        isPrime[1] = false;
        
        // for every prime num 'i' mark all its 
        // multiples (starting from i^2) as not-prime
        for(lli i=2; i<=n; i++)
            if(isPrime[i])
                for(lli m=i*i; m<=n; m += i)
                    isPrime[m] = false;
        
        return isPrime;
    }

public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> isPrime = sieveOfEratosthenes(n);
        lli sumA = 0, sumB = 0;

        for(int i=0; i<n; i++)
        {
            if(isPrime[i])
                sumA += nums[i];
            else
                sumB += nums[i];
        }

        return abs(sumA - sumB);
    }
};