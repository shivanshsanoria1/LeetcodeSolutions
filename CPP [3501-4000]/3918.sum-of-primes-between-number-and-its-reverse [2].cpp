class Solution {
private:
    vector<bool> sieveOfEratosthenes(const int n){
        if(n < 0)
            return {};
        
        // initially assume all nums are prime
        vector<bool> isPrime(n + 1, true);
        // 0 and 1 are not prime
        isPrime[0] = false;
        isPrime[1] = false;
        
        // for every prime num 'i' mark all its 
        // multiples (starting from i^2) as not-prime
        for(int i=2; i<=n; i++)
            if(isPrime[i])
                for(int m=i*i; m<=n; m += i)
                    isPrime[m] = false;
        
        return isPrime;
    }

public:
    // T.C.=O(n*log(log(n))), S.C.=O(n)
    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        const int r = stoi(s);

        vector<bool> isPrime = sieveOfEratosthenes(max(n, r));
        
        int sum = 0;
        for(int num = min(n, r); num <= max(n, r); num++)
            if(isPrime[num])
                sum += num;

        return sum;
    }
};