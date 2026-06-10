class Solution {
public:
    // returns the sum of multiples of x <= n
    int sumOfMultiples(int n, int x)
    {
        int m = n/x; // there are m multiples of x <= n
        return x*m*(m+1)/2;
    }

    int sumOfMultiples(int n) { // T.C.=O(1)
        return sumOfMultiples(n, 3) + sumOfMultiples(n, 5) + sumOfMultiples(n, 7) 
        - sumOfMultiples(n, 15) - sumOfMultiples(n, 35) - sumOfMultiples(n, 21) 
        + sumOfMultiples(n, 105);
    }
};
/*
# the number of multiples of x <= n is m = floor(n/x)
# the sum of first m multiples of x is- 
  1x + 2x + 3x + ... + mx = x(1 + 2 + 3 + ... + m) = x*m*(m+1)/2
*/