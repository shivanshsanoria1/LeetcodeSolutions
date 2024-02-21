class Solution {
public:
    // returns the number of set bits in the input number x
    int setBitsCount(int x){
        int count = 0;
        while(x > 0)
        {
            count += x & 1;
            x = x >> 1;
        }
        return count;
    }

    int minBitFlips(int start, int goal) {
        return setBitsCount(start ^ goal);
    }
};
// setBitsCount(start ^ goal) returns the number of bits where start and goal do not match