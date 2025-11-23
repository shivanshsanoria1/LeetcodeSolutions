class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        while(n % 2 == 0)
            n /= 2;
        return n == 1 ? true : false;
    }
};
// any power of 2 has only 1 set-bit in its binary-representation