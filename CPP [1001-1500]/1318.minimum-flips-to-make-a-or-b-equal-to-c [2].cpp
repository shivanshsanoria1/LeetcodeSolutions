class Solution {
public:
    int minFlips(int a, int b, int c) {
        return __builtin_popcount((a | b) ^ c) + __builtin_popcount(a & b & (~c));
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
# __builtin_popcount((a | b) ^ c) gives the number of bits where (a|b) and c do not match, ie,
1 flip is required for correction
# __builtin_popcount(a & b & (~c)) is to count the number of cases where 2 flips are required
*/