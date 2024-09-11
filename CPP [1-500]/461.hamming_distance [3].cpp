class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};

/*
# for (x ^ y): 
  each 1 bit represents the bit where x and y don't match
  each 0 bit represents the bit where x and y match
  
# similar: [2220. minimum-bit-flips-to-convert-number]
*/