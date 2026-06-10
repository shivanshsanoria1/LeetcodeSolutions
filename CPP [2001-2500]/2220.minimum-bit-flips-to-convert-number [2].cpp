class Solution {
private:
    int countSetBits(int num){
        int count = 0;
        while(num > 0)
        {
            count += num & 1;
            num >>= 1;
        }

        return count;
    }

public:
    int minBitFlips(int start, int goal) {
        return countSetBits(start ^ goal);
    }
};

/*
# for start ^ goal: 
  each 1 bit represents the bit where start and goal don't match
  each 0 bit represents the bit where start and goal match

# similar: [461. hamming-distance]
*/