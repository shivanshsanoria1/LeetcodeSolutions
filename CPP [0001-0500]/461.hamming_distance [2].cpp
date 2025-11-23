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
    int hammingDistance(int x, int y) {
        return countSetBits(x ^ y);
    }
};

/*
# for (x ^ y): 
  each 1 bit represents the bit where x and y don't match
  each 0 bit represents the bit where x and y match
  
# similar: [2220. minimum-bit-flips-to-convert-number]
*/