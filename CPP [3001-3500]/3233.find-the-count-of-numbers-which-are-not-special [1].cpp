class Solution {
private:
    vector<int> sieveOfEratosthenes(int n){
        // initially assume all nums are prime
        vector<int> isPrime(n + 1, true);
        // 0 and 1 are not prime
        isPrime[0] = false;
        isPrime[1] = false;
        
        // for every prime num 'i' mark all its 
        // multiples (starting from i^2) as not-ptime
        for(int i=2; i<=n; i++)
            if(isPrime[i])
                for(int m=i*i; m<=n; m += i)
                    isPrime[m] = false;
        
        return isPrime;
    }

public:
    // T.C.=O(sqrt(r)*ln(ln(sqrt(r)))), S.C.=O(sqrt(r))
    int nonSpecialCount(int l, int r) {
        int sr_left = ceil(sqrt(l));
        int sr_right = floor(sqrt(r));

        vector<int> isPrime = sieveOfEratosthenes(sr_right);

        int specialCount = 0;
        for(int i=sr_left; i<=sr_right; i++)
            if(isPrime[i])
                specialCount++;
        
        return (r-l+1) - specialCount;
    }
};
/*
# proper divisors: divisors of a num other than the num itself
# special num: a num which has exactly 2 proper divisors
# a special num must be the square of a prime num
# a prime num p has only 2 divisors: 1,p and just 1 proper divisor: 1
# square of a prime p^2 has 3 divisors: 1,p,p^2 and 2 proper divisors: 1,p
  thus p^2 is always a special num
# thus our task is to find the nums of the form p^2 in range [l, r]
  or find the nums of the form p in range [sqrt(l), sqrt(r)]
*/