class Solution {
public:
    int minFlips(int a, int b, int c) {
        int mask = (a | b) ^ c;
        return __builtin_popcount(mask) + __builtin_popcount(mask & a & b);
    }
};
/*
  a b (a|b) c flips
  0 0   0   0   0
  0 1   1   0   1
  1 0   1   0   1
  1 1   1   0   2
  0 0   0   1   1
  0 1   1   1   0
  1 0   1   1   0
  1 1   1   1   0
# __builtin_popcount(mask) gives the number of bits where (a|b) and c do not match, ie,
1 flip is required for correction
# __builtin_popcount(mask & a & b) is to count the number of cases where 2 flips are required
*/