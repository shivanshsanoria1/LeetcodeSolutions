class Solution {
private:
    double solve(double x, int n){
        if(n == 0)
            return 1;

        double temp = solve(x, n/2);
        
        return n % 2 == 0 ? temp*temp : temp*temp*x;
    }

public:
    // T.C.=O(logn)
    double myPow(double x, int n) {
        return n < 0 ? 1 / solve(x, abs(n)) : solve(x, n);
    }
};
/*
# if n is even:
  x^n = x^(n/2) * x^(n/2)
# if n is odd:
  x^n = x^((n-1)/2) * x^((n-1)/2) * x
  x^n = x^(n/2) * x^(n/2) * x   ... {using floor division}
# in both the cases x^(n/2) is being repeated in the calculation, 
  so for efficiency we only need to compute it once
*/