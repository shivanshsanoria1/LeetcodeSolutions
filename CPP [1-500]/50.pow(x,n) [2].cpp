class Solution {
public:
    double solve(double x, int n){
        if(n == 0) // base case
            return 1;
        double temp = solve(x, n/2);
        if(n % 2 == 0) // n is even
            return temp*temp;
        else // n is odd
            return temp*temp*x;
    }

    double myPow(double x, int n) {
        return n >= 0 ? solve(x, n) : 1/solve(x, abs(n));
    }
};