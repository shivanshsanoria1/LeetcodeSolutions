class Solution {
public:
    // Bit-manipulation
    int findComplement(int num) {
        // find the min number of bits to represent the given num
        int bits = floor(log2(num)) + 1; 
        // generate a number with number of set bits equal 
        // to the number of bits in the given num
        int maxVal = pow(2, bits) - 1; 

        return maxVal - num;
    }
};

// similar: [1009. complement-of-base-10-intege]