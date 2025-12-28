#define MOD 1000000007

int Solution::solve(int n) { //2*n! ways
    long int ans=2;
    for(int i=2; i<=n; i++)
    {
        ans*= i;
        ans= ans % MOD;
    }
    return ans;
}
