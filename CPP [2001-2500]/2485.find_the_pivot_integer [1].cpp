class Solution {
public:
    int pivotInteger(int n) {
        double sr = sqrt(n*(n+1)/2);
        return floor(sr) == ceil(sr) ? sr : -1;
    }
};
/*
# 1, 2, 3, ..., x-1, x, x+1, ..., n
# x is the pivot number if-
# sum(1, x) = sum(x, n)
# sum(1, x-1) = sum(x+1, n)
# sum(1, x-1) = sum(1, n) - sum(1, x)
# x(x-1)/2 = n(n+1)/2 - x(x+1)/2
# x*x = n(n+1)/2
# x = sqrt(n(n+1)/2)
# x exists if n(n+1)/2 is a perfect square
*/