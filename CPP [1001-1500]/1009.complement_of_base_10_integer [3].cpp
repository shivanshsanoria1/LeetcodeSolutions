class Solution {
public:
    // Bit-manipulation
    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;

        // find the min number of bits to represent the given num
        int bits = floor(log2(n)) + 1; 
        // generate a number with number of set bits equal 
        // to the number of bits in the given num
        int maxVal = pow(2, bits) - 1; 

        return maxVal - n;
    }
};

// similar: [476. number-complement]