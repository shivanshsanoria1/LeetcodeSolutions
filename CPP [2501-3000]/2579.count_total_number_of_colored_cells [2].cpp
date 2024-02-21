class Solution {
public:
    long long coloredCells(int n) {
        long long int ans = 1 + 2 * (long long int)(n-1) * n;
        return ans;
    }
};
/*
# n = 1,2,3,4,...
# ans = 1, 5, 13, 25, ...
# diff = 0, 4, 8, 12, ...
# f(n) = 1 + (4*1 + 4*2 + 4*3 + ... + 4*(n-1)) 
       = 1 + 4*(1 + 2 + 3 + ... + (n-1))
       = 1 + 4*((n-1)*n)/2
       = 1 + 2*(n-1)*n
*/