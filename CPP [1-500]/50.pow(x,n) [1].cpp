class Solution {
public:
    double solve(double x, int n){
        if(n == 0) // base case
            return 1;
        double temp = solve(x, n/2);
        if(n % 2 == 0) // n is even
            return temp*temp;
        else // n is odd
        {
            if(n > 0) // n is +ive
                return temp*temp*x;
            else // n is -ive
                return temp*temp/x;
        }
    }

    double myPow(double x, int n) {
        return solve(x, n);
    }
};