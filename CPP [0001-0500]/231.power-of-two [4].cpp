class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n <= 0 ? false : (n & (n-1)) == 0;
    }
};
/*
# any power of 2 has only 1 set-bit in its binary-representation
# if n is a power of 2, then n & (n-1) is always 0
Eg- for n = 8:
    8 = (1000), 7 = (0111)
    (1000) & (0111) = 0
*/