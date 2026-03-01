class Solution {
private:
    static inline const int MOD = int(1e9) + 7;

    // modular-exponentiation
    int modExpo(int base, int exp){
        if(exp == 0)
            return 1;

        int res = 1;
        while(exp >= 1){
            if(exp % 2 == 1){
                res = (1LL * res * base) % MOD;
                exp--;
            }else{
                base = (1LL * base * base) % MOD;
                exp /= 2;
            }
        }

        return res;
    }

public:
    // T.C.=O(log(k) + log(MOD)), S.C.=O(1)
    // Math
    int sumOfNumbers(int l, int r, int k) {
        int digSum = 0;
        for(int i=l; i<=r; i++)
            digSum += i;
        
        int ans = (1LL * digSum * modExpo(r-l+1, k-1)) % MOD;
        ans = (1LL * ans * (modExpo(10, k) - 1 + MOD)) % MOD;
        ans = (1LL * ans * modExpo(9, MOD - 2)) % MOD;

        return ans;
    }
};

/*
# formula derived for sum:
  sum = digSum * (r-l+1)^(k-1) * (10^k - 1) / 9;
# using a result from Fermat's Little Theorm (FLT)
  a/b = (a * b^(m-2)) (mod m) ... m is prime and gcd(b, m) = 1
  here, a/9 = (a * 9^(MOD - 2)) (mod MOD) ... MOD is prime and gcd(9, MOD) = 1
# Proof: 
  According to FLT: 
  b^(m-1) = 1 (mod m) ... m is prime and gcd(b, m) = 1
  b^(m-2) = b^(-1) (mod m) ... multiply by b^(-1) on both sides
  a/b = a*b^(-1) = a*b^(m-2) (mod m) 
*/