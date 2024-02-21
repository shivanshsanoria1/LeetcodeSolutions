class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n <= 0 ? false : __builtin_popcount(n) == 1;
    }
};
// any power of 2 has only 1 set-bit in its binary-representation
