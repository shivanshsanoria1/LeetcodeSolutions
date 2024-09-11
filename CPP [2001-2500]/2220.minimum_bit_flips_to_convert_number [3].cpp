class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }
};

/*
# for start ^ goal: 
  each 1 bit represents the bit where start and goal don't match
  each 0 bit represents the bit where start and goal match

# similar: [461. hamming-distance]
*/