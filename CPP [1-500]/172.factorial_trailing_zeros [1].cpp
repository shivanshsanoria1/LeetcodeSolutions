class Solution {
public:
    int trailingZeroes(int n) { // Math soln.
        return n/5 + n/25 + n/125 + n/625 + n/3125;
    }
};

/*
# the num of trailing zeros in n! is the num of multiples of 5^1, 5^2, 5^3, ... in n 
  floor(n/5^1) + floor(n/5^2) + floor(n/5^3) + ...
# in maths this formula is extended to infinity 
  but here we only need to continue it upto the point where 5^x <= n
# here max value of n is 10^4
# since 5^5 < 10^4 < 5^6
# max power of 5 needed is 5
# 5^x = 5^5 = 3125
*/