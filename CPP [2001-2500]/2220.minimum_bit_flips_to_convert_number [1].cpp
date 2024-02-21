class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }
};
// __builtin_popcount(start ^ goal) returns the number of bits where start and goal do not match