class Solution {
private:
    #define MOD int(1e9 + 7)

    int solve(int n, int k){
        if(n == 0)
            return k == 0 ? 1 : 0;
        if(k < 0)
            return 0;

        int sum = 0;
        for(int i=1; i<=n; i++)
            sum = (sum + solve(n-1, k-i+1)) % MOD;
        return sum;
    }

public:
    // Recursion
    int kInversePairs(int n, int k) {
        return solve(n, k);
    }
};