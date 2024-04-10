class Solution {
private:
    int solve(unsigned int n){
        if(n == 1)
            return 0;

        if(n % 2 == 0)
            return 1 + solve(n/2);

        return 1 + min(solve(n+1), solve(n-1));
    }

public:
    // T.C.=O(2^x)
    // Recursion
    int integerReplacement(int n) {
        return solve(n);
    }
};