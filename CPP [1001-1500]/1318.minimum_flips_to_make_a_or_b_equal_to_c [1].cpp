class Solution {
public:
    int setBitsCount(int x){
        int count = 0;
        while(x > 0)
        {
            count += x & 1;
            x = x >> 1;
        }
        return count;
    }

    int minFlips(int a, int b, int c) {
        return setBitsCount((a | b) ^ c) + setBitsCount(a & b & (~c));
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
# setBitsCount((a | b) ^ c) gives the number of bits where (a|b) and c do not match, ie,
1 flip is required for correction
# setBitsCount(a & b & (~c)) is to count the number of cases where 2 flips are required
*/